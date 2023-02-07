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


#include "InitializationSettings/AkInitializationSettings.h"

#include "Platforms/AkUEPlatform.h"
#include "HAL/PlatformMemory.h"

#include "AkAudioDevice.h"
#include "AkUnrealHelper.h"
#include "IAkUnrealIOHook.h"
#include "Async/ParallelFor.h"
#include "Platforms/AkUEPlatform.h"

namespace AkInitializationSettings_Helpers
{
	enum { IsLoggingInitialization = true };

	void ParallelFor(void* data, AkUInt32 beginIndex, AkUInt32 endIndex, AkUInt32 /*tileSize*/, AkParallelForFunc func, void* userData, const char* in_szDebugName)
	{
		check(func);
		check(endIndex >= beginIndex);

		if (func != nullptr && endIndex - beginIndex > 0)
		{
			::ParallelFor(endIndex - beginIndex, [data, beginIndex, func, userData](int32 Index)
			{
				check(data);

				AkTaskContext ctx; // Unused in the SoundEngine right now.
				ctx.uIdxThread = 0;
				func(data, beginIndex + Index, beginIndex + Index + 1, ctx, userData);
			});
		}
	}

	void AssertHook(const char* expression, const char* fileName, int lineNumber)
	{
		check(expression);
		check(fileName);
		const FString Expression(expression);
		const FString FileName(fileName);
		UE_LOG(LogAkAudio, Error, TEXT("AKASSERT: %s. File: %s, line: %d"), *Expression, *FileName, lineNumber);
	}

	FAkInitializationStructure::MemoryAllocFunction AllocFunction = nullptr;
	FAkInitializationStructure::MemoryFreeFunction FreeFunction = nullptr;

	void* AkMemAllocVM(size_t size, size_t* /*extra*/)
	{
		return AllocFunction(size);
	}

	void AkMemFreeVM(void* address, size_t /*size*/, size_t /*extra*/, size_t release)
	{
		if (release)
		{
			FreeFunction(address, release);
		}
	}
}


//////////////////////////////////////////////////////////////////////////
// FAkInitializationStructure

FAkInitializationStructure::FAkInitializationStructure()
{
	AK::MemoryMgr::GetDefaultSettings(MemSettings);

	AK::StreamMgr::GetDefaultSettings(StreamManagerSettings);

	AK::StreamMgr::GetDefaultDeviceSettings(DeviceSettings);
	DeviceSettings.uSchedulerTypeFlags = AK_SCHEDULER_DEFERRED_LINED_UP;
	DeviceSettings.uMaxConcurrentIO = AK_UNREAL_MAX_CONCURRENT_IO;

	AK::SoundEngine::GetDefaultInitSettings(InitSettings);
	InitSettings.pfnAssertHook = AkInitializationSettings_Helpers::AssertHook;
	InitSettings.eFloorPlane = AkFloorPlane_XY;
	InitSettings.fGameUnitsToMeters = 100.f;

	AK::SoundEngine::GetDefaultPlatformInitSettings(PlatformInitSettings);

	AK::MusicEngine::GetDefaultInitSettings(MusicSettings);

#if AK_ENABLE_COMMUNICATION
	AK::Comm::GetDefaultInitSettings(CommSettings);
#endif
}

FAkInitializationStructure::~FAkInitializationStructure()
{
	delete[] InitSettings.szPluginDLLPath;
}

void FAkInitializationStructure::SetPluginDllPath(const FString& PlatformArchitecture)
{
	auto& PluginDllPath = InitSettings.szPluginDLLPath;
	delete[] PluginDllPath;
	if (PlatformArchitecture.IsEmpty())
	{
		PluginDllPath = nullptr;
		return;
	}

	auto Path = FAkPlatform::GetDSPPluginsDirectory(PlatformArchitecture);
	auto Length = Path.Len() + 1;
	PluginDllPath = new AkOSChar[Length];
	AKPLATFORM::SafeStrCpy(PluginDllPath, TCHAR_TO_AK(*Path), Length);
}

void FAkInitializationStructure::SetupLLMAllocFunctions(MemoryAllocFunction alloc, MemoryFreeFunction free, bool UseMemTracker)
{
	ensure(alloc == nullptr && free == nullptr || alloc != nullptr && free != nullptr);

	AkInitializationSettings_Helpers::AllocFunction = alloc;
	AkInitializationSettings_Helpers::FreeFunction = free;

#if ENABLE_LOW_LEVEL_MEM_TRACKER
	if (UseMemTracker)
	{
		int32 OutAlignment = 0;
		FPlatformMemory::GetLLMAllocFunctions(AkInitializationSettings_Helpers::AllocFunction, AkInitializationSettings_Helpers::FreeFunction, OutAlignment);
	}
#endif

	if (!AkInitializationSettings_Helpers::AllocFunction || !AkInitializationSettings_Helpers::FreeFunction)
		return;

	MemSettings.pfAllocVM = AkInitializationSettings_Helpers::AkMemAllocVM;
	MemSettings.pfFreeVM = AkInitializationSettings_Helpers::AkMemFreeVM;
}


//////////////////////////////////////////////////////////////////////////
// FAkMainOutputSettings

void FAkMainOutputSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
	auto& OutputSettings = InitializationStructure.InitSettings.settingsMainOutput;

	auto sharesetID = !AudioDeviceShareset.IsEmpty() ? FAkAudioDevice::GetIDFromString(AudioDeviceShareset) : AK_INVALID_UNIQUE_ID;
	OutputSettings.audioDeviceShareset = sharesetID;

	switch (ChannelConfigType)
	{
	case EAkChannelConfigType::Anonymous:
		OutputSettings.channelConfig.SetAnonymous(NumberOfChannels);
		break;

	case EAkChannelConfigType::Standard:
		OutputSettings.channelConfig.SetStandard(ChannelMask);
		break;

	case EAkChannelConfigType::Ambisonic:
		OutputSettings.channelConfig.SetAmbisonic(NumberOfChannels);
		break;
	}

	OutputSettings.ePanningRule = (AkPanningRule)PanningRule;
	OutputSettings.idDevice = DeviceID;
}


//////////////////////////////////////////////////////////////////////////
// FAkSpatialAudioSettings

void FAkSpatialAudioSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
	auto& SpatialAudioInitSettings = InitializationStructure.SpatialAudioInitSettings;
	SpatialAudioInitSettings.uMaxSoundPropagationDepth = MaxSoundPropagationDepth;
	SpatialAudioInitSettings.fMovementThreshold = MovementThreshold;
	SpatialAudioInitSettings.uNumberOfPrimaryRays = NumberOfPrimaryRays;
	SpatialAudioInitSettings.uMaxReflectionOrder = ReflectionOrder;
	SpatialAudioInitSettings.fMaxPathLength = MaximumPathLength;
	SpatialAudioInitSettings.fCPULimitPercentage = CPULimitPercentage;
	SpatialAudioInitSettings.bEnableDiffractionOnReflection = EnableDiffractionOnReflections;
	SpatialAudioInitSettings.bEnableGeometricDiffractionAndTransmission = EnableGeometricDiffractionAndTransmission;
	SpatialAudioInitSettings.bCalcEmitterVirtualPosition = CalcEmitterVirtualPosition;
	SpatialAudioInitSettings.bUseObstruction = UseObstruction;
	SpatialAudioInitSettings.bUseOcclusion = UseOcclusion;
}


//////////////////////////////////////////////////////////////////////////
// FAkCommunicationSettings

void FAkCommunicationSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
#ifndef AK_OPTIMIZED
	auto& CommSettings = InitializationStructure.CommSettings;
	CommSettings.ports.uDiscoveryBroadcast = DiscoveryBroadcastPort;
	CommSettings.ports.uCommand = CommandPort;
	CommSettings.ports.uNotification = NotificationPort;

	const FString GameName = GetCommsNetworkName();
	FCStringAnsi::Strcpy(CommSettings.szAppNetworkName, AK_COMM_SETTINGS_MAX_STRING_SIZE, TCHAR_TO_ANSI(*GameName));
#endif // AK_OPTIMIZED
}

FString FAkCommunicationSettings::GetCommsNetworkName() const
{
	FString CommsNetworkName = NetworkName;

	if (CommsNetworkName.IsEmpty() && FApp::HasProjectName())
	{
		CommsNetworkName = FApp::GetProjectName();
	}

#if WITH_EDITORONLY_DATA
	if (!CommsNetworkName.IsEmpty() && !IsRunningGame())
	{
		CommsNetworkName += TEXT(" (Editor)");
	}
#endif

	return CommsNetworkName;
}


//////////////////////////////////////////////////////////////////////////
// FAkCommunicationSettingsWithSystemInitialization

void FAkCommunicationSettingsWithSystemInitialization::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
	Super::FillInitializationStructure(InitializationStructure);

#if AK_ENABLE_COMMUNICATION
	InitializationStructure.CommSettings.bInitSystemLib = InitializeSystemComms;
#endif
}

void FAkCommunicationSettingsWithCommSelection::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
	Super::FillInitializationStructure(InitializationStructure);

#if AK_ENABLE_COMMUNICATION
	InitializationStructure.CommSettings.commSystem = (AkCommSettings::AkCommSystem)CommunicationSystem;
#endif
}

//////////////////////////////////////////////////////////////////////////
// FAkCommonInitializationSettings

void FAkCommonInitializationSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
	auto& InitSettings = InitializationStructure.InitSettings;
	InitSettings.uMaxNumPaths = MaximumNumberOfPositioningPaths;
	InitSettings.uCommandQueueSize = CommandQueueSize;
	InitSettings.uNumSamplesPerFrame = SamplesPerFrame;

	MainOutputSettings.FillInitializationStructure(InitializationStructure);

	auto& PlatformInitSettings = InitializationStructure.PlatformInitSettings;
	PlatformInitSettings.uNumRefillsInVoice = NumberOfRefillsInVoice;

	SpatialAudioSettings.FillInitializationStructure(InitializationStructure);

	InitializationStructure.MusicSettings.fStreamingLookAheadRatio = StreamingLookAheadRatio;
}


//////////////////////////////////////////////////////////////////////////
// FAkAdvancedInitializationSettings

void FAkAdvancedInitializationSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
	auto& DeviceSettings = InitializationStructure.DeviceSettings;
	DeviceSettings.uIOMemorySize = IO_MemorySize;
	DeviceSettings.uGranularity = IO_Granularity == 0 ? (32 * 1024) : IO_Granularity;
	DeviceSettings.fTargetAutoStmBufferLength = TargetAutoStreamBufferLength;
	DeviceSettings.bUseStreamCache = UseStreamCache;
	DeviceSettings.uMaxCachePinnedBytes = MaximumPinnedBytesInCache;

	auto& InitSettings = InitializationStructure.InitSettings;
	InitSettings.bEnableGameSyncPreparation = EnableGameSyncPreparation;
	InitSettings.uContinuousPlaybackLookAhead = ContinuousPlaybackLookAhead;
	InitSettings.uMonitorQueuePoolSize = MonitorQueuePoolSize;
	InitSettings.uMaxHardwareTimeoutMs = MaximumHardwareTimeoutMs;
	InitSettings.bDebugOutOfRangeCheckEnabled = DebugOutOfRangeCheckEnabled;
	InitSettings.fDebugOutOfRangeLimit = DebugOutOfRangeLimit;
}


//////////////////////////////////////////////////////////////////////////
// FAkAdvancedInitializationSettingsWithMultiCoreRendering

void FAkAdvancedInitializationSettingsWithMultiCoreRendering::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
	Super::FillInitializationStructure(InitializationStructure);

	if (EnableMultiCoreRendering)
	{
		check(FTaskGraphInterface::Get().IsRunning());
		check(FPlatformProcess::SupportsMultithreading());
		check(ENamedThreads::bHasHighPriorityThreads);

		auto& InitSettings = InitializationStructure.InitSettings;
		InitSettings.taskSchedulerDesc.fcnParallelFor = AkInitializationSettings_Helpers::ParallelFor;
		InitSettings.taskSchedulerDesc.uNumSchedulerWorkerThreads = FTaskGraphInterface::Get().GetNumWorkerThreads();
	}
}

static void UELocalOutputFunc(
	AK::Monitor::ErrorCode in_eErrorCode,
	const AkOSChar* in_pszError,
	AK::Monitor::ErrorLevel in_eErrorLevel,
	AkPlayingID in_playingID,
	AkGameObjectID in_gameObjID)
{
	FString AkError(in_pszError);

	if (!IsRunningCommandlet())
	{
		if (in_eErrorLevel == AK::Monitor::ErrorLevel_Message)
		{
			UE_LOG(LogAkAudio, Log, TEXT("%s"), *AkError);
		}
		else
		{
			UE_LOG(LogAkAudio, Error, TEXT("%s"), *AkError);
		}
	}
}

namespace FAkSoundEngineInitialization
{
	bool Initialize(IAkUnrealIOHook* IOHook)
	{
		if (!IOHook)
		{
			UE_LOG(LogAkAudio, Error, TEXT("FAkUnrealIOHook is null."));
			return false;
		}

		const UAkInitializationSettings* InitializationSettings = FAkPlatform::GetInitializationSettings();
		if (InitializationSettings == nullptr)
		{
			UE_LOG(LogAkAudio, Error, TEXT("InitializationSettings could not be found."));
			return false;
		}

		FAkInitializationStructure InitializationStructure;
		InitializationSettings->FillInitializationStructure(InitializationStructure);

		FAkPlatform::PreInitialize(InitializationStructure);

		// Enable AK error redirection to UE log.
		AK::Monitor::SetLocalOutput(AK::Monitor::ErrorLevel_All, UELocalOutputFunc);

		if (AK::MemoryMgr::Init(&InitializationStructure.MemSettings) != AK_Success)
		{
			UE_LOG(LogAkAudio, Error, TEXT("Failed to initialize AK::MemoryMgr."));
			return false;
		}

		if (!AK::StreamMgr::Create(InitializationStructure.StreamManagerSettings))
		{
			UE_LOG(LogAkAudio, Error, TEXT("Failed to initialize AK::StreamMgr."));
			return false;
		}

		if (!IOHook->Init(InitializationStructure.DeviceSettings))
		{
			UE_LOG(LogAkAudio, Error, TEXT("Failed to initialize IOHookDeferred."));
			return false;
		}

		if (AkInitializationSettings_Helpers::IsLoggingInitialization && InitializationStructure.InitSettings.szPluginDLLPath)
		{
			FString DllPath(InitializationStructure.InitSettings.szPluginDLLPath);
			UE_LOG(LogAkAudio, Log, TEXT("Wwise plug-in DLL path: %s"), *DllPath);
		}

		if (AK::SoundEngine::Init(&InitializationStructure.InitSettings, &InitializationStructure.PlatformInitSettings) != AK_Success)
		{
			UE_LOG(LogAkAudio, Error, TEXT("Failed to initialize AK::SoundEngine."));
			return false;
		}

		if (AK::MusicEngine::Init(&InitializationStructure.MusicSettings) != AK_Success)
		{
			UE_LOG(LogAkAudio, Error, TEXT("Failed to initialize AK::MusicEngine."));
			return false;
		}

		if (AK::SpatialAudio::Init(InitializationStructure.SpatialAudioInitSettings) != AK_Success)
		{
			UE_LOG(LogAkAudio, Error, TEXT("Failed to initialize AK::SpatialAudio."));
			return false;
		}

#if AK_ENABLE_COMMUNICATION
		if (AK::Comm::Init(InitializationStructure.CommSettings) != AK_Success)
		{
			UE_LOG(LogAkAudio, Warning, TEXT("Could not initialize Wwise communication."));
		}
		else if (AkInitializationSettings_Helpers::IsLoggingInitialization)
		{
			UE_LOG(LogAkAudio, Log, TEXT("Wwise remote connection application name: %s"), ANSI_TO_TCHAR(InitializationStructure.CommSettings.szAppNetworkName));
		}
#endif

		return true;
	}

	void Finalize()
	{
#if AK_ENABLE_COMMUNICATION
		AK::Comm::Term();
#endif

		AK::MusicEngine::Term();

		if (AK::SoundEngine::IsInitialized())
			AK::SoundEngine::Term();

		if (auto* StreamManager = AK::IAkStreamMgr::Get())
			StreamManager->Destroy();

		if (AK::MemoryMgr::IsInitialized())
			AK::MemoryMgr::Term();
	}
}
