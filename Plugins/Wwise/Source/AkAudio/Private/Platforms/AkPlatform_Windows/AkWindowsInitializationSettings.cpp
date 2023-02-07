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


#include "Platforms/AkPlatform_Windows/AkWindowsInitializationSettings.h"
#include "AkAudioDevice.h"
#include "Runtime/HeadMountedDisplay/Public/IHeadMountedDisplayModule.h"

//////////////////////////////////////////////////////////////////////////
// FAkWindowsAdvancedInitializationSettings

void FAkWindowsAdvancedInitializationSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
	Super::FillInitializationStructure(InitializationStructure);

#if PLATFORM_WINDOWS
	if (UseHeadMountedDisplayAudioDevice && IHeadMountedDisplayModule::IsAvailable())
	{
		FString AudioOutputDevice = IHeadMountedDisplayModule::Get().GetAudioOutputDevice();
		if (!AudioOutputDevice.IsEmpty())
			InitializationStructure.InitSettings.settingsMainOutput.idDevice = AK::GetDeviceIDFromName((wchar_t*)*AudioOutputDevice);
	}
	InitializationStructure.PlatformInitSettings.uMaxSystemAudioObjects = MaxSystemAudioObjects;
#endif // PLATFORM_WINDOWS
}


//////////////////////////////////////////////////////////////////////////
// UAkWindowsInitializationSettings

UAkWindowsInitializationSettings::UAkWindowsInitializationSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UAkWindowsInitializationSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
#if PLATFORM_64BITS
	#define AK_WINDOWS_ARCHITECTURE "x64_"
#else
	#define AK_WINDOWS_ARCHITECTURE "Win32_"
#endif

#ifdef AK_WINDOWS_VS_VERSION
	constexpr auto PlatformArchitecture = AK_WINDOWS_ARCHITECTURE AK_WINDOWS_VS_VERSION;
#else
	constexpr auto PlatformArchitecture = AK_WINDOWS_ARCHITECTURE "vc150";
#endif

#undef AK_WINDOWS_ARCHITECTURE

	InitializationStructure.SetPluginDllPath(PlatformArchitecture);
	InitializationStructure.SetupLLMAllocFunctions();

	CommonSettings.FillInitializationStructure(InitializationStructure);
	CommunicationSettings.FillInitializationStructure(InitializationStructure);
	AdvancedSettings.FillInitializationStructure(InitializationStructure);

#if PLATFORM_WINDOWS
	InitializationStructure.PlatformInitSettings.uSampleRate = CommonSettings.SampleRate;
#endif
}
