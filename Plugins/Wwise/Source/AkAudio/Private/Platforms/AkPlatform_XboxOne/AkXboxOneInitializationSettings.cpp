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


#include "Platforms/AkPlatform_XboxOne/AkXboxOneInitializationSettings.h"
#include "AkAudioDevice.h"

//////////////////////////////////////////////////////////////////////////
// FAkXboxOneAdvancedInitializationSettings

void FAkXboxOneAdvancedInitializationSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
	Super::FillInitializationStructure(InitializationStructure);

#if PLATFORM_XBOXONE
	InitializationStructure.PlatformInitSettings.uMaxXMAVoices = MaximumNumberOfXMAVoices;
	InitializationStructure.PlatformInitSettings.bHwCodecLowLatencyMode = UseHardwareCodecLowLatencyMode;
#endif // PLATFORM_XBOXONE
}

//////////////////////////////////////////////////////////////////////////
// FAkXboxOneApuHeapInitializationSettings

void FAkXboxOneApuHeapInitializationSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
#ifdef AK_XBOXONE_NEED_APU_ALLOC
	// Perform this as early as possible to ensure that no other allocation calls are made before this!
	auto ApuCreateHeapResult = ApuCreateHeap(CachedSize, NonCachedSize);
	if (ApuCreateHeapResult == APU_E_HEAP_ALREADY_ALLOCATED)
	{
		UE_LOG(LogAkAudio, Warning, TEXT("APU heap has already been allocated."));
	}
	else if (ApuCreateHeapResult != S_OK)
	{
		UE_LOG(LogAkAudio, Warning, TEXT("APU heap could not be allocated."));
	}
#endif // AK_XBOXONE_NEED_APU_ALLOC
}


//////////////////////////////////////////////////////////////////////////
// UAkXboxOneInitializationSettings

UAkXboxOneInitializationSettings::UAkXboxOneInitializationSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CommonSettings.SamplesPerFrame = 512;

	CommunicationSettings.DiscoveryBroadcastPort = FAkCommunicationSettings::DefaultDiscoveryBroadcastPort;
	CommunicationSettings.CommandPort = FAkCommunicationSettings::DefaultDiscoveryBroadcastPort + 1;
	CommunicationSettings.NotificationPort = FAkCommunicationSettings::DefaultDiscoveryBroadcastPort + 2;
}

void UAkXboxOneInitializationSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
#ifdef AK_XBOXONE_VS_VERSION
	constexpr auto PlatformArchitecture = "XboxOne_" AK_XBOXONE_VS_VERSION;
#else
	constexpr auto PlatformArchitecture = "XboxOne_vc140";
#endif

	InitializationStructure.SetPluginDllPath(PlatformArchitecture);
	InitializationStructure.SetupLLMAllocFunctions();

	CommonSettings.FillInitializationStructure(InitializationStructure);
	ApuHeapSettings.FillInitializationStructure(InitializationStructure);
	CommunicationSettings.FillInitializationStructure(InitializationStructure);
	AdvancedSettings.FillInitializationStructure(InitializationStructure);

#if PLATFORM_XBOXONE && AK_XBOXONE_INIT_COMMS_MANIFEST
#ifndef AK_OPTIMIZED
	try
	{
		// Make sure networkmanifest.xml is loaded by instantiating a Microsoft.Xbox.Networking object.
		auto secureDeviceAssociationTemplate = Windows::Xbox::Networking::SecureDeviceAssociationTemplate::GetTemplateByName("WwiseDiscovery");
	}
	catch (...)
	{
		UE_LOG(LogAkAudio, Log, TEXT("Could not find Wwise network ports in AppxManifest. Network communication will not be available."));
	}
#endif // AK_OPTIMIZED
#endif // PLATFORM_XBOXONE
}
