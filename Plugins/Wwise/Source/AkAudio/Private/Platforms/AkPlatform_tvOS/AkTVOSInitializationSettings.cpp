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


#include "Platforms/AkPlatform_tvOS/AkTVOSInitializationSettings.h"
#include "AkAudioDevice.h"
#include "InitializationSettings/AkAudioSession.h"

#if PLATFORM_TVOS
#include "Generated/AkTVOSPlugins.h"
#include <AK/Plugin/AkAACFactory.h>
#endif

//////////////////////////////////////////////////////////////////////////
// UAkTVOSInitializationSettings

UAkTVOSInitializationSettings::UAkTVOSInitializationSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CommonSettings.MainOutputSettings.PanningRule = EAkPanningRule::Headphones;
	CommonSettings.MainOutputSettings.ChannelConfigType = EAkChannelConfigType::Standard;
	CommonSettings.MainOutputSettings.ChannelMask = AK_SPEAKER_SETUP_STEREO;
}

void UAkTVOSInitializationSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
	InitializationStructure.SetupLLMAllocFunctions();

	CommonSettings.FillInitializationStructure(InitializationStructure);
	AudioSession.FillInitializationStructure(InitializationStructure);
	CommunicationSettings.FillInitializationStructure(InitializationStructure);
	AdvancedSettings.FillInitializationStructure(InitializationStructure);

#if PLATFORM_TVOS
	InitializationStructure.PlatformInitSettings.uSampleRate = CommonSettings.SampleRate;
	// From FRunnableThreadApple
	InitializationStructure.DeviceSettings.threadProperties.uStackSize = 256 * 1024;
#endif
}
