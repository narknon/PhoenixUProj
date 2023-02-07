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

#include "AkAudioMixer.h"

#include "AkMixerPlatform.h"
#include "AudioMixer.h"
#include "AudioMixerDevice.h"
#include "AkAudioModule.h"

void FAkAudioMixerModule::StartupModule()
{
	// We want to make sure that AkAudio has been initialized
	FModuleManager& ModuleManager = FModuleManager::Get();
	if (!ModuleManager.IsModuleLoaded(TEXT("AkAudio")))
	{
		ModuleManager.LoadModuleChecked(TEXT("AkAudio"));
	}
}


void FAkAudioMixerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

// Implementation of IAudioDeviceModule
bool FAkAudioMixerModule::IsAudioMixerModule() const
{
	return true;
}

Audio::IAudioMixerPlatformInterface* FAkAudioMixerModule::CreateAudioMixerPlatformInterface()
{
	return new FAkMixerPlatform();
}


IMPLEMENT_MODULE( FAkAudioMixerModule, AkAudioMixer )
