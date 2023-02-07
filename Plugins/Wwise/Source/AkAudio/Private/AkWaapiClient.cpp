/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/


/*=============================================================================
	AkWaapiClient.cpp: Audiokinetic WAAPI interface object.

	Unreal is RHS with Y and Z swapped (or technically LHS with flipped axis)

=============================================================================*/

/*------------------------------------------------------------------------------------
	Audio includes.
------------------------------------------------------------------------------------*/
#include "AkWaapiClient.h"
#include "AkAudioDevice.h"
#include "AkSettings.h"
#include "AkSettingsPerUser.h"
#include "Serialization/JsonSerializer.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"
#include "Async/Async.h"
#include "Misc/ScopeLock.h"
#include "Misc/CoreDelegates.h"

#if AK_SUPPORT_WAAPI

#if PLATFORM_WINDOWS
// Problem with the Windows API as a whole: it uses noexcept straight up, whether exceptions are used or not, generating a warning that Unreal then converts to an error.
#if _MSC_VER >= 1910
#pragma warning (disable: 4577)
#endif // _MSC_VER >= 1910
#endif // #if PLATFORM_WINDOWS

#include "AK/WwiseAuthoringAPI/AkAutobahn/Client.h"
#include "AK/WwiseAuthoringAPI/AkAutobahn/AkJson.h"
#include "AK/WwiseAuthoringAPI/AkAutobahn/JsonProvider.h"

typedef AK::WwiseAuthoringAPI::JsonProvider JsonProvider;
#endif

DEFINE_LOG_CATEGORY(LogAkWaapiClient);

/*------------------------------------------------------------------------------------
Statics and Globals
------------------------------------------------------------------------------------*/
FAkWaapiClient* g_AkWaapiClient = nullptr;

/*------------------------------------------------------------------------------------
FAkWaapiClientConnectionHandler
------------------------------------------------------------------------------------*/

FAkWaapiClientConnectionHandler::FAkWaapiClientConnectionHandler(FAkWaapiClient& in_Client) : m_Client(in_Client)
{
	WaitEvent = FPlatformProcess::GetSynchEventFromPool(true);
}

FAkWaapiClientConnectionHandler::~FAkWaapiClientConnectionHandler()
{
	FPlatformProcess::ReturnSynchEventToPool(WaitEvent);
	WaitEvent = nullptr;
}

void FAkWaapiClientConnectionHandler::RegisterAutoConnectChangedCallback()
{
	FScopeLock Lock(&AkSettingsSection);
	if (auto AkSettingsPerUser = GetDefault<UAkSettingsPerUser>())
	{
		AutoConnectChangedHandle = AkSettingsPerUser->OnAutoConnectChanged.AddLambda([this, AkSettingsPerUser]()
		{
			ResetReconnectionDelay();
			if (AkSettingsPerUser->bAutoConnectToWAAPI)
				WaitEvent->Trigger();
			else
			{
				m_Client.BroadcastConnectionLost();
			}
		});
	}
}

void FAkWaapiClientConnectionHandler::Wake()
{
	WaitEvent->Trigger();
}

/* FRunnable interface */
bool FAkWaapiClientConnectionHandler::Init()
{
	return true;
}

uint32 FAkWaapiClientConnectionHandler::Run()
{
#if AK_SUPPORT_WAAPI
	AKASSERT(!IsInGameThread());
	while (!ThreadShouldExit)
	{
		if (!m_Client.IsProjectLoaded())
		{
			/** Check if we should attempt to reconnect according to the Wwise Plugin Settings. */
			bool bReconnect = !m_Client.IsDisconnecting() && !m_Client.AppIsExiting();
			{
				FScopeLock Lock(&AkSettingsSection);
				if (auto AkSettingsPerUser = GetDefault<UAkSettingsPerUser>())
				{
					bReconnect = AkSettingsPerUser->bAutoConnectToWAAPI;
				}
			}
			/** If we previously had a connection (and we're not exiting), broadcast connection lost.*/
			if (hadConnection && !m_Client.AppIsExiting())
			{
				if (bReconnect)
					UE_LOG(LogAkWaapiClient, Warning, TEXT("Lost connection to WAAPI client. Attempting reconnection ..."));
				hadConnection = false;
				AsyncTask(ENamedThreads::GameThread, [this]()
				{
					m_Client.BroadcastConnectionLost();
				});
			}
			/** If we should reconnect, attempt a reconnection and, if successful, call the client's connection established function on the game thread.
			*  Otherwise, print a failed connection log.
			*/
			if (bReconnect)
			{
				if (AttemptReconnect())
				{
					hadConnection = true;
					m_Client.SetConnectionClosing(false);
					ResetReconnectionDelay();
					AsyncTask(ENamedThreads::GameThread, [this]()
					{
						m_Client.ConnectionEstablished();
					});
				}
				else
				{
					if (LogOutputCount.GetValue() < 7)
					{
						UE_LOG(LogAkWaapiClient, Warning, TEXT("Failed to connect to WAAPI client on local host. Trying again in %i seconds."), ReconnectDelay.GetValue());
						LogOutputCount.Increment();
					}
				}
				/** Delay the next reconnection attempt according to the ReconnectDelay value. */
				const int iCurrentDelay = ReconnectDelay.GetValue();
				if (iCurrentDelay < m_iMaxReconnectDelay)
					ReconnectDelay.Set(iCurrentDelay * 2);
				WaitEvent->Wait(iCurrentDelay * 1000);
				WaitEvent->Reset();
			}
			else
			{
				/** We shouldn't attempt reconnection, so wait until the auto-reconnect option is changed. */
				WaitEvent->Wait();
				WaitEvent->Reset();
			}

		}
		else /** We're already connected. Check connection status. */
		{
			TSharedRef<FJsonObject> args = MakeShareable(new FJsonObject());
			TSharedRef<FJsonObject> options = MakeShareable(new FJsonObject());
			TSharedPtr<FJsonObject> result = MakeShareable(new FJsonObject());
			m_Client.Call(ak::wwise::core::getInfo, args, options, result, 500, true);
			WaitEvent->Wait(ConnectionMonitorDelay.GetValue() * 1000);
			WaitEvent->Reset();
		}

	}
#endif
	return 0;
}

void FAkWaapiClientConnectionHandler::ResetReconnectionDelay()
{
	bool bReconnect = true;
	{
		FScopeLock Lock(&AkSettingsSection);
		if (auto AkSettingsPerUser = GetDefault<UAkSettingsPerUser>())
		{
			bReconnect = AkSettingsPerUser->bAutoConnectToWAAPI;
		}
	}
	if (bReconnect && !m_Client.AppIsExiting() && !m_Client.IsDisconnecting())
	{
		ReconnectDelay.Set(2);
		LogOutputCount.Set(0);
	}
}

void FAkWaapiClientConnectionHandler::Stop()
{
	ThreadShouldExit = true;
}

void FAkWaapiClientConnectionHandler::Exit()
{
	ThreadShouldExit = true;
}

bool FAkWaapiClientConnectionHandler::AttemptReconnect()
{
#if AK_SUPPORT_WAAPI
	if (m_Client.AttemptConnection())
	{
		UE_LOG(LogAkWaapiClient, Log, TEXT("Successfully connected to Wwise Authoring on localhost."));
		return true;
	}
#endif
	return false;
}

/*------------------------------------------------------------------------------------
Helpers
------------------------------------------------------------------------------------*/
struct FAkWaapiClientImpl
{
	void Init(FAkWaapiClient& in_Client)
	{
#if AK_SUPPORT_WAAPI
		m_pConnectionHandler = MakeShareable(new FAkWaapiClientConnectionHandler(in_Client));
		FString ThreadName(FString::Printf(TEXT("WAAPIClientConnectionThread%i"), ThreadCounter.Increment()));
		m_pReconnectionThread = MakeShareable(FRunnableThread::Create(m_pConnectionHandler.Get(),
			*ThreadName, 0,
			EThreadPriority::TPri_BelowNormal));

		m_pConnectionHandler->RegisterAutoConnectChangedCallback();
#endif
	}

	~FAkWaapiClientImpl()
	{
#if AK_SUPPORT_WAAPI
		if (m_pConnectionHandler.IsValid())
		{
			m_pConnectionHandler->Exit();
			m_pConnectionHandler->Wake();
		}

		if (m_pReconnectionThread.IsValid())
		{
			if (!m_pReconnectionThread->Kill(true))
			{
				UE_LOG(LogAkWaapiClient, Error, TEXT("WAAPI Connection Thread Failed to Exit!"));
			}
		}
#endif
	}

#if AK_SUPPORT_WAAPI
	/** Map containing id keys and WampEventCallback values. */
	TMap<uint64_t, WampEventCallback> m_wampEventCallbackMap;
	AK::WwiseAuthoringAPI::Client m_Client;
	/** A non-0 value indicates that UE is exiting. */
	FThreadSafeCounter AppExitingCounter = 0;
	FThreadSafeCounter ThreadCounter;
	/** Thread on which the WAAPI connection is monitored. */
	TSharedPtr<FRunnableThread> m_pReconnectionThread;
	/** The connection to WAAPI is monitored by this connection handler.
	*  It tries to reconnect when connection is lost, and continuously polls WAAPI for the connection status when WAAPI is connected.
	*  This behaviour can be disabled in AkSettings using the AutoConnectToWaapi boolean option.
	*/
	TSharedPtr<FAkWaapiClientConnectionHandler> m_pConnectionHandler;
	FCriticalSection ClientSection;

	/** Flag indicating whether the correct project has been loaded (it's "correct" if it matches the Project Path in AkSettings.) */
	FThreadSafeBool bProjectLoaded = false;

	/** Flag indicating if the connection is being killed and shouldn't be restarted. */
	FThreadSafeBool bIsConnectionClosing = false;
#endif
};

bool FAkWaapiClient::JsonObjectToString(const TSharedRef<FJsonObject>& in_jsonObject, FString& ou_jsonObjectString)
{
	TSharedRef<TJsonWriter<>> JsonWriterArgs = TJsonWriterFactory<>::Create(&ou_jsonObjectString);
	auto result = FJsonSerializer::Serialize(in_jsonObject, JsonWriterArgs);
	if (!result)
	{
		UE_LOG(LogAkWaapiClient, Log, TEXT("Unable to get a string representation of the Json Object."));
	}
	JsonWriterArgs->Close();
	return result;
}

#if AK_SUPPORT_WAAPI
void WampEventCallbacks(const uint64_t& in_subscriptionId, const JsonProvider& in_rJson)
{
	if (g_AkWaapiClient == nullptr)
		return;

	auto wampEventCallbacks = g_AkWaapiClient->GetWampEventCallback(in_subscriptionId);
	if (!wampEventCallbacks)
		return;

	TSharedPtr<FJsonObject> ueJsonObject;

	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(UTF8_TO_TCHAR(in_rJson.GetJsonString().c_str()));
	if (!FJsonSerializer::Deserialize(Reader, ueJsonObject) || !ueJsonObject.IsValid())
	{
		UE_LOG(LogAkWaapiClient, Log, TEXT("Unable to deserialize a JSON object from the string : %s"), UTF8_TO_TCHAR(in_rJson.GetJsonString().c_str()));
		return;
	}

	wampEventCallbacks->Execute(in_subscriptionId, ueJsonObject);
}
#endif


/*------------------------------------------------------------------------------------
Implementation.
------------------------------------------------------------------------------------*/

FAkWaapiClient::~FAkWaapiClient()
{
	delete m_Impl;
}

void FAkWaapiClient::Initialize()
{
#if AK_SUPPORT_WAAPI
	if (!g_AkWaapiClient)
	{
		g_AkWaapiClient = new FAkWaapiClient();
		FCoreDelegates::OnPreExit.AddLambda([]
		{
			if (g_AkWaapiClient != nullptr)
			{
				g_AkWaapiClient->m_Impl->AppExitingCounter.Increment();
				TArray<uint64_t> aSubscriptionIDs;
				g_AkWaapiClient->m_Impl->m_wampEventCallbackMap.GetKeys(aSubscriptionIDs);
				TSharedPtr<FJsonObject> jsonResult = MakeShareable(new FJsonObject());
				for (auto iSubscriptionID : aSubscriptionIDs)
				{
					g_AkWaapiClient->Unsubscribe(iSubscriptionID, jsonResult);
				}
			}
			DeleteInstance();
		});
	}
#endif
}

/** Returns the singleton instance of FAkWaapiClient. Be sure to call FAkWaapiClient::Initialize() first (i.e. during Module startup). */
FAkWaapiClient* FAkWaapiClient::Get()
{
	return g_AkWaapiClient;
}

bool FAkWaapiClient::AppIsExiting()
{
#if AK_SUPPORT_WAAPI
	return m_Impl->AppExitingCounter.GetValue() != 0;
#else
	return false;
#endif
}

void FAkWaapiClient::SetConnectionClosing(bool isClosing)
{
#if AK_SUPPORT_WAAPI
	m_Impl->bIsConnectionClosing = isClosing;
#endif
}

void FAkWaapiClient::DeleteInstance()
{
#if AK_SUPPORT_WAAPI
	if (g_AkWaapiClient == nullptr)
		return;

	g_AkWaapiClient->OnClientBeginDestroy.Broadcast();
	g_AkWaapiClient->m_Impl->bIsConnectionClosing = true;
	g_AkWaapiClient->m_Impl->m_Client.Disconnect();
	delete g_AkWaapiClient;
	g_AkWaapiClient = nullptr;
#endif
}

bool FAkWaapiClient::IsDisconnecting()
{
#if AK_SUPPORT_WAAPI
	return m_Impl->bIsConnectionClosing;
#else
	return false;
#endif
}

WampEventCallback* FAkWaapiClient::GetWampEventCallback(const uint64_t& in_subscriptionId)
{
#if AK_SUPPORT_WAAPI
	return m_Impl->m_wampEventCallbackMap.Find(in_subscriptionId);
#else
	return nullptr;
#endif
}

bool FAkWaapiClient::IsProjectLoaded()
{
#if AK_SUPPORT_WAAPI
	if (g_AkWaapiClient == nullptr)
		return false;

	if (!g_AkWaapiClient->IsConnected())
	{
		return false;
	}

	return g_AkWaapiClient->m_Impl->bProjectLoaded;
#else
	return false;
#endif
}

/** This is called when the reconnection handler successfully connects to WAAPI.
*  We check if the correct project is loaded on a background thread. If it is, we broadcast OnProjectLoaded.
*  We also subscribe to ak::wwise::core::project::loaded in order to check the project whenever one is loaded.
*  If an incorrect project is loaded we broadcast OnConnectionLost.
*/
void FAkWaapiClient::ConnectionEstablished()
{
#if AK_SUPPORT_WAAPI
	ensure(IsInGameThread());
	if (g_AkWaapiClient == nullptr)
		return;

	// Broadcast OnProjectLoaded. If we are here, it means connection was successful, and that the correct project is
	// loaded and available
	OnProjectLoaded.Broadcast();

	//We also subscribe to ak::wwise::core::project::loaded in order to check the project whenever one is loaded.
	auto projectLoadedCallback = WampEventCallback::CreateLambda([this](uint64_t id, TSharedPtr<FJsonObject> in_UEJsonObject)
	{
		AsyncTask(ENamedThreads::GameThread, [this, id, in_UEJsonObject]()
		{
			m_Impl->bProjectLoaded = CheckProjectLoaded();
			if (m_Impl->bProjectLoaded)
			{
				OnProjectLoaded.Broadcast();
			}
			else if (!AppIsExiting())//If an incorrect project is loaded we broadcast OnConnectionLost
			{
				BroadcastConnectionLost();
			}
		});
	});

	TSharedPtr<FJsonObject> projectLoadedSubscriptionResult = MakeShareable(new FJsonObject());
	TSharedRef<FJsonObject> projectLoadedOptions = MakeShareable(new FJsonObject());
	uint64_t projectLoadedSubscriptionID;
	g_AkWaapiClient->Subscribe(ak::wwise::core::project::loaded, projectLoadedOptions, projectLoadedCallback, projectLoadedSubscriptionID, projectLoadedSubscriptionResult);

	//And we need to subscribe to ak::wwise::core::project::postClosed such that we are able to re-connect to WAAPI (for example if Wwise is closed then opened again).
	auto projectClosedCallback = WampEventCallback::CreateLambda([this](uint64_t id, TSharedPtr<FJsonObject> in_UEJsonObject)
	{
		AsyncTask(ENamedThreads::GameThread, [this]()
		{
			BroadcastConnectionLost();
		});
	});
	TSharedPtr<FJsonObject> projectClosedSubscriptionResult = MakeShareable(new FJsonObject());
	TSharedRef<FJsonObject> projectClosedOptions = MakeShareable(new FJsonObject());
	uint64_t projectClosedSubscriptionID;
	g_AkWaapiClient->Subscribe(ak::wwise::core::project::postClosed, projectClosedOptions, projectClosedCallback, projectClosedSubscriptionID, projectClosedSubscriptionResult);
#endif
}

/** Returns the path of the Wwise project as defined in AkSettings (WWise Plugin Settings). */
bool FAkWaapiClient::GetProjectPath(TSharedPtr<FJsonObject>& inOutJsonResult, FString& ProjectPath)
{
#if AK_SUPPORT_WAAPI
	TArray<TSharedPtr<FJsonValue>> inFromItems;
	inFromItems.Add(MakeShareable(new FJsonValueString("Project")));
	const bool bSuccess = WAAPIGet(WAAPIGetFromOption::OF_TYPE, inFromItems, (AkInt64)WAAPIGetReturnOptionFlag::FILEPATH,
		inOutJsonResult, WAAPIGetTransformOption::NONE, TArray<TSharedPtr<FJsonValue>>(), true);
	if (bSuccess)
	{
		if (inOutJsonResult->HasField(FAkWaapiClient::WAAPIStrings::RETURN))
		{
			TArray<TSharedPtr<FJsonValue>> returnJson = inOutJsonResult->GetArrayField(FAkWaapiClient::WAAPIStrings::RETURN);
			if (returnJson.Num() > 0)
				ProjectPath = returnJson[0]->AsObject()->GetStringField(FAkWaapiClient::WAAPIStrings::FILEPATH);
		}
	}
	return bSuccess;
#else
	return true;
#endif
}

// WAAPI can become temporarily unavailable from time to time, this should be taken into account in the design.
// Please note that you shouldn't use this kind of design unless you know your call is accurate. If you do this
// and the error is caused by an argument problem, you might end up with an infinite retry loop.
FString GetAndWaitForCurrentProject(float RetrySleepTimeSeconds)
{
	FString ProjectPath;
	static int RetryCount = 5;
	while (g_AkWaapiClient->IsConnected())
	{
		TSharedPtr<FJsonObject> JsonResult = MakeShareable(new FJsonObject());
		if (g_AkWaapiClient->GetProjectPath(JsonResult, ProjectPath))
			break;

		if (RetrySleepTimeSeconds > 0.0f)
		{
			if (--RetryCount == 0)
			{
				RetryCount = 5;
				return {};
			}

			// Avoid flooding with requests while WAAPI is unavailable.
			FPlatformProcess::Sleep(RetrySleepTimeSeconds);
		}
	}

	return ProjectPath;
}

/** Checks if the currently loaded Wwise project matches the project path set in AkSettings (Wwise plugin settings).
*  NTOE: This function will block while Wwise has a modal window open. It should not be called on the Game thread.
*/
bool FAkWaapiClient::CheckProjectLoaded()
{
#if AK_SUPPORT_WAAPI
	if (g_AkWaapiClient == nullptr)
		return false;

	if (!g_AkWaapiClient->IsConnected())
	{
		g_AkWaapiClient->m_Impl->m_pConnectionHandler->ResetReconnectionDelay();
		return false;
	}

	if (const UAkSettings* AkSettings = GetDefault<UAkSettings>())
	{
		auto ProjectPathString = AkSettings->WwiseProjectPath.FilePath;
		while (ProjectPathString.StartsWith("../"))
		{
			ProjectPathString = ProjectPathString.Replace(*FString("../"), *FString(""));
		}
		auto RelativePath = ProjectPathString.Replace(*FString("/"), *FString("\\"));
		FString sCurrentlyLoadedProjectPath = GetAndWaitForCurrentProject(1.0f);
		if (sCurrentlyLoadedProjectPath.Contains(RelativePath))
			return true;
	}
#endif
	return false;
}

void FAkWaapiClient::BroadcastConnectionLost()
{
#if AK_SUPPORT_WAAPI
	m_Impl->bProjectLoaded = false;
	OnConnectionLost.Broadcast();
#endif
}

bool FAkWaapiClient::IsConnected()
{
#if AK_SUPPORT_WAAPI
	return m_Impl->m_Client.IsConnected();
#else
	return false;
#endif
}


bool FAkWaapiClient::AttemptConnection()
{
	bool bConnected = false;
#if AK_SUPPORT_WAAPI
	if (const UAkSettingsPerUser* AkSettingsPerUser = GetDefault<UAkSettingsPerUser>())
	{
		bConnected = m_Impl->m_Client.Connect(TCHAR_TO_UTF8(*AkSettingsPerUser->WaapiIPAddress), AkSettingsPerUser->WaapiPort);
	}
	else
	{
		bConnected = m_Impl->m_Client.Connect(WAAPI_LOCAL_HOST_IP_STRING, WAAPI_PORT);
	}

	if (bConnected)
	{
		bool bProjectLoaded = CheckProjectLoaded();
		if (!bProjectLoaded)
		{
			// We successfully connected, but the wrong project is open (or getting the project timed out). Disconnect.
			// We will attemps reconnection later.
			m_Impl->m_Client.Disconnect();
			bConnected = false;
		}
		m_Impl->bProjectLoaded = bProjectLoaded;
	}
#endif
	return bConnected;
}

bool FAkWaapiClient::Subscribe(const char* in_uri, const FString& in_options, WampEventCallback in_callback,
	uint64& out_subscriptionId, FString& out_result, int in_iTimeoutMs /*= 500*/)
{
	bool eResult = false;
#if AK_SUPPORT_WAAPI
	std::string out_resultString("");
	if (IsConnected())
	{
		if (!m_Impl->bIsConnectionClosing)
		{
			// Call for the AK WAAPI method using string params.
			{
				FScopeLock Lock(&m_Impl->ClientSection);
				eResult = m_Impl->m_Client.Subscribe(in_uri, TCHAR_TO_UTF8(*in_options), &WampEventCallbacks, out_subscriptionId, out_resultString, in_iTimeoutMs);
			}
			if (eResult)
			{
				m_Impl->m_wampEventCallbackMap.Add(out_subscriptionId, in_callback);
			}
			else
			{
				UE_LOG(LogAkWaapiClient, Log, TEXT("Subscription failed: %s"), *FString(UTF8_TO_TCHAR(out_resultString.c_str())));
			}
			out_result = FString(UTF8_TO_TCHAR(out_resultString.c_str()));
		}
	}
	else
	{
		m_Impl->m_pConnectionHandler->ResetReconnectionDelay();
	}
#endif
	return eResult;
}

bool FAkWaapiClient::Subscribe(const char* in_uri, const TSharedRef<FJsonObject>& in_options, WampEventCallback in_callback,
	uint64& out_subscriptionId, TSharedPtr<FJsonObject>& out_result, int in_iTimeoutMs /*= 500*/)
{
	bool eResult = false;
#if AK_SUPPORT_WAAPI
	FString in_optionsString = TEXT("");

	// Retrieve the options data string from the Json object.
	JsonObjectToString(in_options, in_optionsString);

	FString out_resultString(TEXT(""));
	// Call for the AK WAAPI method using string params.
	eResult = Subscribe(in_uri, in_optionsString, in_callback, out_subscriptionId, out_resultString, in_iTimeoutMs);

	if (!eResult)
	{
		// Deserialize a JSON object from the string.
		TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(out_resultString);

		if ((!FJsonSerializer::Deserialize(Reader, out_result) || !out_result.IsValid()) && IsConnected())
		{
			UE_LOG(LogAkWaapiClient, Log, TEXT("Subscribe: Output result -> unable to deserialize the Json object from the string : %s"), *out_resultString);
		}
	}
#endif
	return eResult;
}

bool FAkWaapiClient::Unsubscribe(const uint64_t& in_subscriptionId, FString& out_result, int in_iTimeoutMs /*= 500*/, bool in_bSilenceLog /*= false*/)
{
	bool eResult = false;
#if AK_SUPPORT_WAAPI
	if (IsConnected())
	{
		if (!m_Impl->bIsConnectionClosing)
		{
			std::string out_resultString("");
			// Call the AK WAAPI method.
			{
				FScopeLock Lock(&m_Impl->ClientSection);
				eResult = m_Impl->m_Client.Unsubscribe(in_subscriptionId, out_resultString, in_iTimeoutMs);
			}
			if (eResult)
			{
				if (m_Impl->m_wampEventCallbackMap.Contains(in_subscriptionId))
					m_Impl->m_wampEventCallbackMap.Remove(in_subscriptionId);
			}
			else if (!in_bSilenceLog)
			{
				UE_LOG(LogAkWaapiClient, Log, TEXT("Unsubscription failed: %s"), *FString(UTF8_TO_TCHAR(out_resultString.c_str())));
			}
			out_result = FString(UTF8_TO_TCHAR(out_resultString.c_str()));
		}
	}
	else
	{
		m_Impl->m_pConnectionHandler->ResetReconnectionDelay();
	}
#endif
	return eResult;
}

bool FAkWaapiClient::Unsubscribe(const uint64_t& in_subscriptionId, TSharedPtr<FJsonObject>& out_result, int in_iTimeoutMs /*= 500*/, bool in_bSilenceLog /*= false*/)
{
	bool eResult = false;
#if AK_SUPPORT_WAAPI
	if (IsConnected())
	{
		FString out_resultString(TEXT(""));
		// Call the AK WAAPI method.
		eResult = Unsubscribe(in_subscriptionId, out_resultString, in_iTimeoutMs, in_bSilenceLog);

		if (!eResult)
		{
			// Deserialize a JSON object from the string
			TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(out_resultString);

			if ((!FJsonSerializer::Deserialize(Reader, out_result) || !out_result.IsValid()) && IsConnected())
			{
				UE_LOG(LogAkWaapiClient, Log, TEXT("Unsubscribe: Output result -> unable to deserialize the Json object from the string : %s"), *out_resultString);
			}
		}
	}
	else
	{
		m_Impl->m_pConnectionHandler->ResetReconnectionDelay();
	}
#endif
	return eResult;
}

bool FAkWaapiClient::RemoveWampEventCallback(const uint64_t in_subscriptionId)
{
#if AK_SUPPORT_WAAPI
	if (m_Impl->m_wampEventCallbackMap.Contains(in_subscriptionId))
	{
		m_Impl->m_wampEventCallbackMap.Remove(in_subscriptionId);
		return true;
	}
#endif

	return false;
}

bool FAkWaapiClient::Call(const char* in_uri, const FString& in_args, const FString& in_options, FString& out_result, int in_iTimeoutMs /*= 500*/, bool silenceLog /* = false*/)
{
	bool eResult = false;
#if AK_SUPPORT_WAAPI
	if (IsConnected())
	{
		if (!m_Impl->bIsConnectionClosing)
		{
			std::string out_resultString("");
			// Call the AK WAAPI method.
			{
				FScopeLock Lock(&m_Impl->ClientSection);
				eResult = m_Impl->m_Client.Call(in_uri, TCHAR_TO_UTF8(*in_args), TCHAR_TO_UTF8(*in_options), out_resultString, in_iTimeoutMs);
			}
			if (!eResult && !silenceLog)
			{
				UE_LOG(LogAkWaapiClient, Log, TEXT("Call failed: %s"), *FString(UTF8_TO_TCHAR(out_resultString.c_str())));
			}
			out_result = FString(UTF8_TO_TCHAR(out_resultString.c_str()));
		}
	}
	else
	{
		m_Impl->m_pConnectionHandler->ResetReconnectionDelay();
	}
#endif
	return eResult;
}

bool FAkWaapiClient::Call(const char* in_uri, const TSharedRef<FJsonObject>& in_args, const TSharedRef<FJsonObject>& in_options,
	TSharedPtr<FJsonObject>& out_result, int in_iTimeoutMs /*= 500*/, bool silenceLog /*= false*/)
{
	bool eResult = false;
#if AK_SUPPORT_WAAPI
	FString in_argsString = TEXT("");
	FString in_optionsString = TEXT("");

	// Make sure the arguments are valid Json data.
	JsonObjectToString(in_args, in_argsString);

	// Make sure the options are valid Json data.
	JsonObjectToString(in_options, in_optionsString);

	FString out_resultString(TEXT(""));
	// Call the AK WAAPI method.
	eResult = Call(in_uri, in_argsString, in_optionsString, out_resultString, in_iTimeoutMs, silenceLog);

	// Deserialize a JSON object from the string.
	TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(out_resultString);

	if (!FJsonSerializer::Deserialize(Reader, out_result) || !out_result.IsValid())
	{
		if (!silenceLog && IsConnected())
			UE_LOG(LogAkWaapiClient, Log, TEXT("Output result -> unable to deserialize a JSON object from the string : %s"), *out_resultString);
	}
#endif
	return eResult;
}

FAkWaapiClient::FAkWaapiClient()
	: m_Impl(new FAkWaapiClientImpl)
{
	m_Impl->Init(*this);
}

/** Sets in_outParentGUID to the object ID of a parent of object in_objectGUID of type in_strType. */
void FAkWaapiClient::GetParentOfType(FGuid in_objectGUID, FGuid& in_outParentGUID, FString in_strType)
{
#if AK_SUPPORT_WAAPI
	if (g_AkWaapiClient == nullptr)
		return;

	/* Construct the relevant WAAPI json fields. */
	AkInt64 returnFlags = (AkInt64)WAAPIGetReturnOptionFlag::ID |
		(AkInt64)WAAPIGetReturnOptionFlag::TYPE;

	TArray<TSharedPtr<FJsonValue>> fromID;
	fromID.Add(MakeShareable(new FJsonValueString(in_objectGUID.ToString(EGuidFormats::DigitsWithHyphensInBraces))));

	TSharedPtr<FJsonObject> outJsonResult;
	if (!WAAPIGet(WAAPIGetFromOption::ID, fromID, returnFlags, outJsonResult))
		return;

	if (!outJsonResult->HasField(WAAPIStrings::RETURN))
		return;

	TArray<TSharedPtr<FJsonValue>> returnJson = outJsonResult->GetArrayField(WAAPIStrings::RETURN);
	if (returnJson.Num() <= 0)
		return;

	FString objectType;
	{
		TSharedPtr<FJsonObject> typeObject = returnJson[0]->AsObject();
		if (typeObject->HasField(WAAPIStrings::TYPE))
			objectType = typeObject->GetStringField(WAAPIStrings::TYPE);
	}
	in_outParentGUID = in_objectGUID;

	if (objectType.Equals(in_strType, ESearchCase::IgnoreCase))
		return;

	TSharedPtr<FJsonObject> select = MakeShareable(new FJsonObject());
	TArray<TSharedPtr<FJsonValue>> selectJsonArray;
	selectJsonArray.Add(MakeShareable(new FJsonValueString(WAAPIStrings::PARENT)));
	select->SetArrayField(WAAPIStrings::SELECT, selectJsonArray);
	TArray<TSharedPtr<FJsonValue>> transform;
	transform.Add(MakeShareable(new FJsonValueObject(select)));

	while (!objectType.Equals(in_strType, ESearchCase::IgnoreCase))
	{
		fromID.Empty();
		fromID.Add(MakeShareable(new FJsonValueString(in_outParentGUID.ToString(EGuidFormats::DigitsWithHyphensInBraces))));
		outJsonResult = MakeShareable(new FJsonObject());
		if (!WAAPIGet(WAAPIGetFromOption::ID, fromID, returnFlags, outJsonResult, WAAPIGetTransformOption::SELECT, selectJsonArray))
			break;

		if (!outJsonResult->HasField(WAAPIStrings::RETURN))
			continue;

		TArray<TSharedPtr<FJsonValue>> aReturnJson = outJsonResult->GetArrayField(WAAPIStrings::RETURN);
		TSharedPtr<FJsonObject> returnObject = aReturnJson[0]->AsObject();
		if (returnObject->HasField(WAAPIStrings::TYPE))
			objectType = returnObject->GetStringField(WAAPIStrings::TYPE);
		if (returnObject->HasField(WAAPIStrings::ID))
			FGuid::Parse(returnObject->GetStringField(WAAPIStrings::ID), in_outParentGUID);
	}
#endif
}

bool FAkWaapiClient::IsProjectDirty()
{
#if AK_SUPPORT_WAAPI
	/* Ensure that Initialize() has been called! */
	AKASSERT(g_AkWaapiClient != nullptr);

	TArray<TSharedPtr<FJsonValue>> inFromItems;
	AkInt64 iReturnOptions = (uint64_t)WAAPIGetReturnOptionFlag::WORKUNIT_IS_DIRTY;
	TSharedPtr<FJsonObject> pJsonResult = MakeShareable(new FJsonObject());
	inFromItems.Add(MakeShareable(new FJsonValueString("WorkUnit")));
	WAAPIGet(WAAPIGetFromOption::OF_TYPE, inFromItems, iReturnOptions, pJsonResult);
	if (pJsonResult->HasField(WAAPIStrings::RETURN))
	{
		TArray<TSharedPtr<FJsonValue>> returnJson = pJsonResult->GetArrayField(WAAPIStrings::RETURN);
		FString workunitDirty = GetReturnOptionString(WAAPIGetReturnOptionFlag::WORKUNIT_IS_DIRTY);
		for (auto json : returnJson)
		{
			if (json->AsObject()->HasField(workunitDirty) && json->AsObject()->GetBoolField(workunitDirty))
				return true;
		}
	}
#endif
	return false;
}

/**
* WAAPI Structures
*/

FString FAkWaapiClient::GetFromOptionString(WAAPIGetFromOption from)
{
	switch (from)
	{
	case WAAPIGetFromOption::ID:      return "id";
	case WAAPIGetFromOption::SEARCH:  return "search";
	case WAAPIGetFromOption::PATH:    return "path";
	case WAAPIGetFromOption::OF_TYPE: return "ofType";
	case WAAPIGetFromOption::QUERY:   return "query";
	default: AKASSERT(false && "From option unhandled"); return "";
	}
}

FString FAkWaapiClient::GetTransformOptionString(WAAPIGetTransformOption transform)
{
	switch (transform)
	{
	case WAAPIGetTransformOption::SELECT: return "select";
	case WAAPIGetTransformOption::RANGE:  return "range";
	case WAAPIGetTransformOption::WHERE:  return "where";
	case WAAPIGetTransformOption::NONE:   return "";
	default: AKASSERT(false && "Transform option unhandled"); return "";
	}
}

FAkWaapiClient::WAAPIGetReturnOptionFlag FAkWaapiClient::GetReturnOptionFlagValue(int in_iFlagIndex)
{
	return (WAAPIGetReturnOptionFlag)(AkInt64)pow(2, in_iFlagIndex);
}

FString FAkWaapiClient::GetReturnOptionString(WAAPIGetReturnOptionFlag returnOption)
{
	switch (returnOption)
	{
	case WAAPIGetReturnOptionFlag::ID:                                  return "id";
	case WAAPIGetReturnOptionFlag::NAME:                                return "name";
	case WAAPIGetReturnOptionFlag::NOTES:                               return "notes";
	case WAAPIGetReturnOptionFlag::TYPE:                                return "type";
	case WAAPIGetReturnOptionFlag::PATH:                                return "path";
	case WAAPIGetReturnOptionFlag::PARENT:                              return "parent";
	case WAAPIGetReturnOptionFlag::OWNER:                               return "owner";
	case WAAPIGetReturnOptionFlag::IS_PLAYABLE:                         return "isPlayable";
	case WAAPIGetReturnOptionFlag::SHORT_ID:                            return "shortId";
	case WAAPIGetReturnOptionFlag::CATEGORY:                            return "category";
	case WAAPIGetReturnOptionFlag::FILEPATH:                            return "filePath";
	case WAAPIGetReturnOptionFlag::WORKUNIT:                            return "workunit";
	case WAAPIGetReturnOptionFlag::CHILDREN_COUNT:                      return "childrenCount";
	case WAAPIGetReturnOptionFlag::MUSIC_TRANSITION_ROOT:               return "music:transitionRoot";
	case WAAPIGetReturnOptionFlag::MUSIC_PLAYLIST_ROOT:                 return "music:playlistRoot";
	case WAAPIGetReturnOptionFlag::SOUND_ORIGINAL_WAV_FILE_PATH:        return "sound:originalWavFilePath";
	case WAAPIGetReturnOptionFlag::SOUND_CONVERTED_WEM_FILE_PATH:       return "sound:convertedWemFilePath";
	case WAAPIGetReturnOptionFlag::SOUNDBANK_BANK_FILE_PATH:            return "soundbank:bnkFilePath";
	case WAAPIGetReturnOptionFlag::AUDIO_SOURCE_PLAYBACK_DURATION:      return "audioSource:playbackDuration";
	case WAAPIGetReturnOptionFlag::AUDIO_SOURCE_MAX_DURATION_SOURCE:    return "audioSource:maxDurationSource";
	case WAAPIGetReturnOptionFlag::AUDIO_SOURCE_TRIM_VALUES:            return "audioSource:trimValues";
	case WAAPIGetReturnOptionFlag::WORKUNIT_IS_DEFAULT:                 return "workunit:isDefault";
	case WAAPIGetReturnOptionFlag::WORKUNIT_TYPE:                       return "workunit:type";
	case WAAPIGetReturnOptionFlag::WORKUNIT_IS_DIRTY:                   return "workunit:isDirty";
	default: AKASSERT(false && "Return option unhandled"); return "";
	}
}
/**
* JSon Helpers
*/
TSharedRef<FJsonObject> FAkWaapiClient::CreateWAAPIGetArgumentJson(WAAPIGetFromOption in_FromOption, TArray<TSharedPtr<FJsonValue>> in_FromItems,
	WAAPIGetTransformOption in_TransformOption /*= WAAPIGetTransformOption::NONE*/,
	TArray<TSharedPtr<FJsonValue>> in_TransformItems /*= TArray<TSharedPtr<FJsonValue>>()*/)
{
	TSharedRef<FJsonObject> args = MakeShareable(new FJsonObject());
	TSharedPtr<FJsonObject> from = MakeShareable(new FJsonObject());
	from->SetArrayField(GetFromOptionString(in_FromOption), in_FromItems);
	args->SetObjectField(FAkWaapiClient::WAAPIStrings::FROM, from);
	if (in_TransformOption != WAAPIGetTransformOption::NONE && in_TransformItems.Num() > 0)
	{
		TArray<TSharedPtr<FJsonValue>> transformArgArray;
		TSharedPtr<FJsonObject> transformObjectArg = MakeShareable(new FJsonObject());
		transformObjectArg->SetArrayField(GetTransformOptionString(in_TransformOption), in_TransformItems);
		transformArgArray.Add(MakeShareable(new FJsonValueObject(transformObjectArg)));
		args->SetArrayField(FAkWaapiClient::WAAPIStrings::TRANSFORM, transformArgArray);
	}
	return args;
}

TSharedRef<FJsonObject> FAkWaapiClient::CreateWAAPIGetReturnOptionsJson(AkInt64 ReturnOptions)
{
	TSharedRef<FJsonObject> options = MakeShareable(new FJsonObject());
	TArray<TSharedPtr<FJsonValue>> StructJsonArray;
	for (int bitIndex = 0; bitIndex < (int)WAAPIGetReturnOptionFlag::NUM_FLAGS; ++bitIndex)
	{
		WAAPIGetReturnOptionFlag returnOption = GetReturnOptionFlagValue(bitIndex);
		if ((ReturnOptions & (AkInt64)returnOption) != 0)
		{
			StructJsonArray.Add(MakeShareable(new FJsonValueString(GetReturnOptionString(returnOption))));
		}
	}

	options->SetArrayField(FAkWaapiClient::WAAPIStrings::RETURN, StructJsonArray);
	return options;
}

/**
* WAAPI Helpers
*/

bool FAkWaapiClient::WAAPIGet(WAAPIGetFromOption inFromField,
	TArray<TSharedPtr<FJsonValue>> inFromItems,
	AkInt64 inReturnOptionsFlags,
	TSharedPtr<FJsonObject>& outJsonResult,
	WAAPIGetTransformOption inTransformField /*= WAAPIGetTransformOption::NONE*/,
	TArray<TSharedPtr<FJsonValue>> inTransformItems /*= TArray<TSharedPtr<FJsonValue>>()*/,
	bool in_bSilenceLog /*= false*/)
{
#if AK_SUPPORT_WAAPI
	TSharedRef<FJsonObject> getArgsJson = CreateWAAPIGetArgumentJson(inFromField, inFromItems, inTransformField, inTransformItems);
	TSharedRef<FJsonObject> returnOptionsJson = CreateWAAPIGetReturnOptionsJson(inReturnOptionsFlags);

	if (g_AkWaapiClient != nullptr && g_AkWaapiClient->IsConnected())
	{
		if (g_AkWaapiClient->Call(ak::wwise::core::object::get, getArgsJson, returnOptionsJson, outJsonResult, 500, in_bSilenceLog))
			return true;
		else if (!in_bSilenceLog)
			UE_LOG(LogAkWaapiClient, Log, TEXT("Call to ak.wwise.core.object.get Failed"));
	}
#endif
	return false;
}

bool FAkWaapiClient::GetGUIDForObjectOfTypeWithName(FGuid& io_GUID, const FString& in_sTypeName, const FString& in_sName)
{
#if AK_SUPPORT_WAAPI
	TArray<TSharedPtr<FJsonValue>> nameArray;
	nameArray.Add(MakeShareable(new FJsonValueString(in_sName)));
	TSharedPtr<FJsonObject> outJsonResult = MakeShareable(new FJsonObject());
	AkInt64 returnOptionFlags = (AkInt64)WAAPIGetReturnOptionFlag::ID | (AkInt64)WAAPIGetReturnOptionFlag::NAME | (AkInt64)WAAPIGetReturnOptionFlag::TYPE;
	if (WAAPIGet(WAAPIGetFromOption::SEARCH, nameArray, returnOptionFlags, outJsonResult))
	{
		if (outJsonResult->HasField(WAAPIStrings::RETURN))
		{
			TArray<TSharedPtr<FJsonValue>> returnJson = outJsonResult->GetArrayField(WAAPIStrings::RETURN);
			for (auto json : returnJson)
			{
				auto jsonObj = json->AsObject();
				auto name = jsonObj->GetStringField(WAAPIStrings::NAME);
				auto typeName = jsonObj->GetStringField(WAAPIStrings::TYPE);
				if (name == in_sName && typeName.Equals(in_sTypeName, ESearchCase::IgnoreCase))
				{
					auto iD = jsonObj->GetStringField(WAAPIStrings::ID);
					FGuid::Parse(iD, io_GUID);
					return true;
				}
			}
		}
	}
#endif
	return false;
}

void FAkWaapiClient::SaveProject()
{
#if AK_SUPPORT_WAAPI
	TSharedRef<FJsonObject> argsJson = MakeShareable(new FJsonObject());
	TSharedRef<FJsonObject> optionsJson = MakeShareable(new FJsonObject());
	TSharedPtr<FJsonObject> outputJson = MakeShareable(new FJsonObject());
	if (g_AkWaapiClient->IsConnected())
	{
		g_AkWaapiClient->Call(ak::wwise::core::project::save, argsJson, optionsJson, outputJson);
	}
#endif
}

const FString FAkWaapiClient::WAAPIStrings::BACK_SLASH = TEXT("\\");
const FString FAkWaapiClient::WAAPIStrings::ID = TEXT("id");
const FString FAkWaapiClient::WAAPIStrings::RETURN = TEXT("return");
const FString FAkWaapiClient::WAAPIStrings::PATH = TEXT("path");
const FString FAkWaapiClient::WAAPIStrings::FILEPATH = TEXT("filePath");
const FString FAkWaapiClient::WAAPIStrings::FROM = TEXT("from");
const FString FAkWaapiClient::WAAPIStrings::NAME = TEXT("name");
const FString FAkWaapiClient::WAAPIStrings::TYPE = TEXT("type");
const FString FAkWaapiClient::WAAPIStrings::CHILDREN = TEXT("children");
const FString FAkWaapiClient::WAAPIStrings::CHILDREN_COUNT = TEXT("childrenCount");
const FString FAkWaapiClient::WAAPIStrings::ANCESTORS = TEXT("ancestors");
const FString FAkWaapiClient::WAAPIStrings::DESCENDANTS = TEXT("descendants");
const FString FAkWaapiClient::WAAPIStrings::WOKUNIT_TYPE = TEXT("workunit:type");
const FString FAkWaapiClient::WAAPIStrings::FOLDER = TEXT("Folder");
const FString FAkWaapiClient::WAAPIStrings::PHYSICAL_FOLDER = TEXT("PhysicalFolder");
const FString FAkWaapiClient::WAAPIStrings::SEARCH = TEXT("search");
const FString FAkWaapiClient::WAAPIStrings::PARENT = TEXT("parent");
const FString FAkWaapiClient::WAAPIStrings::SELECT = TEXT("select");
const FString FAkWaapiClient::WAAPIStrings::TRANSFORM = TEXT("transform");
const FString FAkWaapiClient::WAAPIStrings::OBJECT = TEXT("object");
const FString FAkWaapiClient::WAAPIStrings::OBJECTS = TEXT("objects");
const FString FAkWaapiClient::WAAPIStrings::VALUE = TEXT("value");
const FString FAkWaapiClient::WAAPIStrings::COMMAND = TEXT("command");
const FString FAkWaapiClient::WAAPIStrings::TRANSPORT = TEXT("transport");
const FString FAkWaapiClient::WAAPIStrings::ACTION = TEXT("action");
const FString FAkWaapiClient::WAAPIStrings::PLAY = TEXT("play");
const FString FAkWaapiClient::WAAPIStrings::STOP = TEXT("stop");
const FString FAkWaapiClient::WAAPIStrings::STOPPED = TEXT("stopped");
const FString FAkWaapiClient::WAAPIStrings::DISPLAY_NAME = TEXT("displayName");
const FString FAkWaapiClient::WAAPIStrings::DELETE_ITEMS = TEXT("Delete Items");
const FString FAkWaapiClient::WAAPIStrings::DRAG_DROP_ITEMS = TEXT("Drag Drop Items");
const FString FAkWaapiClient::WAAPIStrings::UNDO = TEXT("Undo");
const FString FAkWaapiClient::WAAPIStrings::REDO = TEXT("Redo");
const FString FAkWaapiClient::WAAPIStrings::STATE = TEXT("state");
const FString FAkWaapiClient::WAAPIStrings::OF_TYPE = TEXT("ofType");
const FString FAkWaapiClient::WAAPIStrings::PROJECT = TEXT("Project");
const FString FAkWaapiClient::WAAPIStrings::PROPERTY = TEXT("property");
const FString FAkWaapiClient::WAAPIStrings::VOLUME = TEXT("Volume");
const FString FAkWaapiClient::WAAPIStrings::FIND_IN_PROJECT_EXPLORER = TEXT("FindInProjectExplorerSyncGroup1");
const FString FAkWaapiClient::WAAPIStrings::TRIMMED_DURATION = TEXT("trimmedDuration");

const FString FAkWaapiClient::WwiseTypeStrings::SOUND = TEXT("Sound");
const FString FAkWaapiClient::WwiseTypeStrings::WORKUNIT = TEXT("WorkUnit");

const FString FAkWaapiClient::AudioPeaksStrings::Args::OBJECT = TEXT("object");
const FString FAkWaapiClient::AudioPeaksStrings::Args::NUM_PEAKS = TEXT("numPeaks");
const FString FAkWaapiClient::AudioPeaksStrings::Args::TIME_FROM = TEXT("timeFrom");
const FString FAkWaapiClient::AudioPeaksStrings::Args::TIME_TO = TEXT("timeTo");
const FString FAkWaapiClient::AudioPeaksStrings::Args::CROSS_CHANNEL_PEAKS = TEXT("getCrossChannelPeaks");
const FString FAkWaapiClient::AudioPeaksStrings::Results::PEAKS_BINARY = TEXT("peaksBinaryStrings");
const FString FAkWaapiClient::AudioPeaksStrings::Results::MAX_ABS_VALUE = TEXT("maxAbsValue");
const FString FAkWaapiClient::AudioPeaksStrings::Results::PEAKS_ARRAY_LENGTH = TEXT("peaksArrayLength");
const FString FAkWaapiClient::AudioPeaksStrings::Results::PEAKS_DATA_SIZE = TEXT("peaksDataSize");

const FString FAkWaapiClient::PropertyChangedStrings::RequiredOptions::OBJECT = TEXT("object");
const FString FAkWaapiClient::PropertyChangedStrings::RequiredOptions::PROPERTY = TEXT("property");
const FString FAkWaapiClient::PropertyChangedStrings::OptionalOptions::RETURN = TEXT("return");
const FString FAkWaapiClient::PropertyChangedStrings::OptionalOptions::PLATFORM = TEXT("platform");

const FString FAkWaapiClient::AudioSourceProperties::TRIM_END = TEXT("TrimEnd");
const FString FAkWaapiClient::AudioSourceProperties::TRIM_BEGIN = TEXT("TrimBegin");

const FString FAkWaapiClient::PlaybackDurationStrings::MIN = TEXT("playbackDurationMin");
const FString FAkWaapiClient::PlaybackDurationStrings::MAX = TEXT("playbackDurationMax");
const FString FAkWaapiClient::PlaybackDurationStrings::TYPE = TEXT("playbackDurationType");

const FString FAkWaapiClient::TrimValuesStrings::TRIM_BEGIN = TEXT("trimBegin");
const FString FAkWaapiClient::TrimValuesStrings::TRIM_END = TEXT("trimEnd");
// end