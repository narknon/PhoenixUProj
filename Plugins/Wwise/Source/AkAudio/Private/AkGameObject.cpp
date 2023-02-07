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
	AkGameObject.cpp:
=============================================================================*/

#include "AkGameObject.h"
#include "AkAudioEvent.h"
#include "AkMediaAsset.h"
#include "AkComponentCallbackManager.h"
#include "AkRtpc.h"
#include "AkMediaAsset.h"


class FPostAssociatedEventAction : public FAkPendingLatentAction
{
public:
	FName ExecutionFunction;
	int32 OutputLink = 0;
	FWeakObjectPtr CallbackTarget;
	int32* PlayingID = nullptr;
	TFuture<AkPlayingID> FuturePlayingID;
	TArray<FAkExternalSourceInfo> ExternalSources;
	UAkAudioEvent* AkEvent = nullptr;
	bool* bGameObjectStarted= nullptr;

	FPostAssociatedEventAction(const FLatentActionInfo& LatentInfo, int32* PlayingID, const TArray<FAkExternalSourceInfo>& ExtSrc, UAkAudioEvent* Event, bool* bStarted)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, PlayingID(PlayingID)
		, ExternalSources(ExtSrc)
		, AkEvent(Event)
		, bGameObjectStarted(bStarted)
	{
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		bool futureIsReady = FuturePlayingID.IsReady();
		if (futureIsReady)
		{
			*PlayingID = FuturePlayingID.Get();
			if (bGameObjectStarted != nullptr)
			{
				*bGameObjectStarted = true;
			}
		}
		else if (AkEvent)
		{
			for (auto ExtSrc : ExternalSources)
			{
				if (ExtSrc.ExternalSourceAsset)
				{
					ExtSrc.ExternalSourceAsset->AddPlayingID(AkEvent->ShortID, *PlayingID);
					if (bGameObjectStarted != nullptr)
					{
						*bGameObjectStarted = true;
					}
				}
			}
		}

		Response.FinishAndTriggerIf(futureIsReady, ExecutionFunction, OutputLink, CallbackTarget);
	}

#if WITH_EDITOR
	virtual FString GetDescription() const override
	{
		return TEXT("Waiting for posted AkEvent to load media.");
	}
#endif
};

UAkGameObject::UAkGameObject(const class FObjectInitializer& ObjectInitializer) :
Super(ObjectInitializer)
{
	bStarted = false;
}

int32 UAkGameObject::PostAssociatedAkEvent(int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const TArray<FAkExternalSourceInfo>& ExternalSources)
{
	return PostAkEvent(AkAudioEvent, CallbackMask, PostEventCallback, ExternalSources, EventName);
}

int32 UAkGameObject::PostAssociatedAkEvent(int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback)
{
	return PostAkEvent(AkAudioEvent, CallbackMask, PostEventCallback, TArray<FAkExternalSourceInfo>(), EventName);
}

int32 UAkGameObject::PostAkEvent(class UAkAudioEvent * AkEvent, int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const TArray<FAkExternalSourceInfo>& ExternalSources, const FString& in_EventName)
{
	AkPlayingID playingID = PostAkEventByNameWithDelegate(GET_AK_EVENT_NAME(AkEvent, in_EventName), CallbackMask, PostEventCallback, ExternalSources);
	if (AkEvent && playingID != AK_INVALID_PLAYING_ID)
	{
		AkEvent->PinInGarbageCollector(playingID);
	}
	return playingID;
}

int32 UAkGameObject::PostAkEvent(class UAkAudioEvent * AkEvent, int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const FString& in_EventName)
{
	AkPlayingID playingID = PostAkEventByNameWithDelegate(GET_AK_EVENT_NAME(AkEvent, in_EventName), CallbackMask, PostEventCallback, TArray<FAkExternalSourceInfo>());
	if (AkEvent && playingID != AK_INVALID_PLAYING_ID)
	{
		AkEvent->PinInGarbageCollector(playingID);
	}
	return playingID;
}

AkPlayingID UAkGameObject::PostAkEventByNameWithDelegate(const FString& in_EventName, int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const TArray<FAkExternalSourceInfo>& ExternalSources)
{
	AkPlayingID playingID = AK_INVALID_PLAYING_ID;

	auto AudioDevice = FAkAudioDevice::Get();
	if (AudioDevice)
	{
		if (ExternalSources.Num() > 0)
		{
			FAkSDKExternalSourceArray SDKExternalSrcInfo(ExternalSources);
			playingID = AudioDevice->PostEvent(in_EventName, this, PostEventCallback, CallbackMask, SDKExternalSrcInfo.ExternalSourceArray);
			if (playingID != AK_INVALID_PLAYING_ID)
			{
				for (auto ExtSrc : ExternalSources)
				{
					if (ExtSrc.ExternalSourceAsset)
					{
						ExtSrc.ExternalSourceAsset->AddPlayingID(FAkAudioDevice::GetIDFromString(in_EventName), playingID);
					}
				}
			}
		}
		else
		{
			playingID = AudioDevice->PostEvent(in_EventName, this, PostEventCallback, CallbackMask);
		}
		if (playingID != AK_INVALID_PLAYING_ID)
			bStarted = true;
	}

	return playingID;
}

void UAkGameObject::PostAssociatedAkEventAsync(const UObject* WorldContextObject, int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo, int32& PlayingID)
{
	PostAkEventAsyncByEvent(WorldContextObject, AkAudioEvent, CallbackMask, PostEventCallback, ExternalSources, LatentInfo, PlayingID);
}

void UAkGameObject::PostAkEventAsync(const UObject* WorldContextObject,
	UAkAudioEvent* AkEvent,
	int32& PlayingID,
	int32 CallbackMask,
	const FOnAkPostEventCallback& PostEventCallback,
	const TArray<FAkExternalSourceInfo>& ExternalSources,
	FLatentActionInfo LatentInfo
)
{
	PostAkEventAsyncByEvent(WorldContextObject, AkEvent, CallbackMask, PostEventCallback, ExternalSources, LatentInfo, PlayingID);
}

void UAkGameObject::PostAkEventAsyncByEvent(const UObject* WorldContextObject,
	class UAkAudioEvent* AkEvent,
	int32 CallbackMask,
	const FOnAkPostEventCallback& PostEventCallback,
	const TArray<FAkExternalSourceInfo>& ExternalSources,
	FLatentActionInfo LatentInfo,
	int32& PlayingID
)
{
	AkDeviceAndWorld DeviceAndWorld(WorldContextObject);
	FLatentActionManager& LatentActionManager = DeviceAndWorld.CurrentWorld->GetLatentActionManager();
	FPostAssociatedEventAction* NewAction = LatentActionManager.FindExistingAction<FPostAssociatedEventAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
	if (!NewAction)
	{
		NewAction = new FPostAssociatedEventAction(LatentInfo, &PlayingID, ExternalSources, AkEvent, &bStarted);
		if (ExternalSources.Num() > 0)
		{
			TSharedPtr<FAkSDKExternalSourceArray, ESPMode::ThreadSafe> SDKExternalSrcInfo = MakeShared<FAkSDKExternalSourceArray, ESPMode::ThreadSafe>(ExternalSources);
			NewAction->FuturePlayingID = DeviceAndWorld.AkAudioDevice->PostEventAsync(AkEvent, this, PostEventCallback, CallbackMask, SDKExternalSrcInfo);
		}
		else
		{
			NewAction->FuturePlayingID = DeviceAndWorld.AkAudioDevice->PostEventAsync(AkEvent, this, PostEventCallback, CallbackMask);
		}

		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, NewAction);
	}
}

void UAkGameObject::SetRTPCValue(const UAkRtpc* RTPCValue, float Value, int32 InterpolationTimeMs, FString RTPC) const
{
	if (FAkAudioDevice::Get())
	{
		if (RTPCValue)
		{
			AK::SoundEngine::SetRTPCValue(RTPCValue->ShortID, Value, GetAkGameObjectID(), InterpolationTimeMs);
		}
		else
		{
			AK::SoundEngine::SetRTPCValue(TCHAR_TO_AK(*RTPC), Value, GetAkGameObjectID(), InterpolationTimeMs);
		}
	}
}

void UAkGameObject::GetRTPCValue(const UAkRtpc* RTPCValue, ERTPCValueType InputValueType, float& Value, ERTPCValueType& OutputValueType, FString RTPC, int32 PlayingID) const
{
	if (FAkAudioDevice::Get())
	{
		AK::SoundEngine::Query::RTPCValue_type RTPCType = (AK::SoundEngine::Query::RTPCValue_type)InputValueType;

		if (RTPCValue)
		{
			AK::SoundEngine::Query::GetRTPCValue(RTPCValue->ShortID, GetAkGameObjectID(), PlayingID, Value, RTPCType);
		}
		else
		{
			AK::SoundEngine::Query::GetRTPCValue(TCHAR_TO_AK(*RTPC), GetAkGameObjectID(), PlayingID, Value, RTPCType);
		}

		OutputValueType = (ERTPCValueType)RTPCType;
	}
}

void UAkGameObject::GetRTPCValue(FString RTPC, int32 PlayingID, ERTPCValueType InputValueType, float& Value, ERTPCValueType& OutputValueType) const
{
	GetRTPCValue(nullptr, InputValueType, Value, OutputValueType, RTPC, PlayingID);
}

bool UAkGameObject::VerifyEventName(const FString& in_EventName) const
{
	const bool IsEventNameEmpty = in_EventName.IsEmpty();
	if (IsEventNameEmpty)
	{
		FString OwnerName = FString(TEXT(""));
		FString ObjectName = GetName();

		const auto owner = GetOwner();
		if (owner)
			OwnerName = owner->GetName();

		UE_LOG(LogAkAudio, Warning, TEXT("[%s.%s] AkGameObject: Attempted to post an empty AkEvent name."), *OwnerName, *ObjectName);
	}

	return !IsEventNameEmpty;
}

bool UAkGameObject::AllowAudioPlayback() const
{
	UWorld* CurrentWorld = GetWorld();
	return (CurrentWorld && CurrentWorld->AllowAudioPlayback() && !IsBeingDestroyed());
}

AkGameObjectID UAkGameObject::GetAkGameObjectID() const
{
	return (AkGameObjectID)this;
}

void UAkGameObject::Stop()
{
	if (HasActiveEvents() && FAkAudioDevice::Get() && IsRegisteredWithWwise)
	{
		AK::SoundEngine::StopAll(GetAkGameObjectID());
		AK::SoundEngine::RenderAudio();
	}
}

bool UAkGameObject::HasActiveEvents() const
{
	auto CallbackManager = FAkComponentCallbackManager::GetInstance();
	return (CallbackManager != nullptr) && CallbackManager->HasActiveEvents(GetAkGameObjectID());
}
