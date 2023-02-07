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


#include "Platforms/AkPlatform_Hololens/AkHololensInitializationSettings.h"
#include "AkAudioDevice.h"
#include "Runtime/HeadMountedDisplay/Public/IHeadMountedDisplayModule.h"

//////////////////////////////////////////////////////////////////////////
// FAkHololensAdvancedInitializationSettings

void FAkHololensAdvancedInitializationSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
	Super::FillInitializationStructure(InitializationStructure);

#if PLATFORM_HOLOLENS
	if (UseHeadMountedDisplayAudioDevice && IHeadMountedDisplayModule::IsAvailable())
	{
		FString AudioOutputDevice = IHeadMountedDisplayModule::Get().GetAudioOutputDevice();
		if (!AudioOutputDevice.IsEmpty())
			InitializationStructure.InitSettings.settingsMainOutput.idDevice = AK::GetDeviceIDFromName((wchar_t*)*AudioOutputDevice);
	}
#endif // PLATFORM_HOLOLENS
}


//////////////////////////////////////////////////////////////////////////
// UAkHololensInitializationSettings

UAkHololensInitializationSettings::UAkHololensInitializationSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UAkHololensInitializationSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{

#ifdef AK_HOLOLENS_VS_VERSION
	constexpr auto PlatformArchitecture = "UWP_ARM64_" AK_HOLOLENS_VS_VERSION;
#else
	constexpr auto PlatformArchitecture = "UWP_ARM64_vc150";
#endif

	InitializationStructure.SetPluginDllPath(PlatformArchitecture);
	InitializationStructure.SetupLLMAllocFunctions();

	CommonSettings.FillInitializationStructure(InitializationStructure);
	CommunicationSettings.FillInitializationStructure(InitializationStructure);
	AdvancedSettings.FillInitializationStructure(InitializationStructure);

#if PLATFORM_HOLOLENS
	InitializationStructure.PlatformInitSettings.uSampleRate = CommonSettings.SampleRate;
#endif
}
