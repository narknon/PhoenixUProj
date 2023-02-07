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


#include "Platforms/AkPlatform_Mac/AkMacInitializationSettings.h"
#include "AkAudioDevice.h"

#if PLATFORM_MAC
#include <AK/Plugin/AkAACFactory.h>
#endif

//////////////////////////////////////////////////////////////////////////
// UAkMacInitializationSettings

UAkMacInitializationSettings::UAkMacInitializationSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UAkMacInitializationSettings::FillInitializationStructure(FAkInitializationStructure& InitializationStructure) const
{
	InitializationStructure.SetPluginDllPath("Mac");
	InitializationStructure.SetupLLMAllocFunctions();

	CommonSettings.FillInitializationStructure(InitializationStructure);
	CommunicationSettings.FillInitializationStructure(InitializationStructure);
	AdvancedSettings.FillInitializationStructure(InitializationStructure);

#if PLATFORM_MAC
	InitializationStructure.PlatformInitSettings.uSampleRate = CommonSettings.SampleRate;
	// From FRunnableThreadMac
	InitializationStructure.DeviceSettings.threadProperties.uStackSize = 4 * 1024 * 1024;
#endif
}
