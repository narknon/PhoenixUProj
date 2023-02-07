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


#include "AudioMixerInputComponent.h"
#include "AkAudioDevice.h"
#include "AkAudioInputManager.h"
#include "AkAudioEvent.h"

#define AK_AUDIO_INPUT_EVENT_NAME "Play_UnrealAudio"

FAudioMixerInputComponent::FAudioMixerInputComponent() :
	PlayingID(AK_INVALID_PLAYING_ID)
{
	auto Device = FAkAudioDevice::Get();
	if (Device != nullptr)
	{
		Device->RegisterComponent(GetAkGameObjectID());
	}
}

FAudioMixerInputComponent::~FAudioMixerInputComponent()
{
	if (OnNextBuffer.IsBound())
	{
		OnNextBuffer.Unbind();
	}
	auto Device = FAkAudioDevice::Get();
	Device->UnregisterComponent(GetAkGameObjectID());
}

bool FAudioMixerInputComponent::FillSamplesBuffer(uint32 NumChannels, uint32 NumSamples, float** BufferToFill)
{
	if (OnNextBuffer.IsBound())
	{
		OnNextBuffer.Execute(NumChannels, NumSamples, BufferToFill);
	}
	return true;
}

/** This callback is used to provide the Wwise sound engine with the required audio format. */
void FAudioMixerInputComponent::GetChannelConfig(AkAudioFormat& OutAudioFormat)
{
	const int sampleRate = 48000;
	OutAudioFormat.uSampleRate = sampleRate;
	OutAudioFormat.channelConfig.SetStandard(AK_SPEAKER_SETUP_STEREO);

	UE_LOG(LogAkAudio, Log, TEXT("Wwise Channel configuration:"));
	UE_LOG(LogAkAudio, Log, TEXT("Wwise Input Sample Rate: %d"), OutAudioFormat.uSampleRate);
	UE_LOG(LogAkAudio, Log, TEXT("Wwise Channel num: %d"), 2);
}

AkPlayingID FAudioMixerInputComponent::PostAssociatedAudioInputEvent(UAkAudioEvent* InputEvent)
{
	// TODO Handle failure
	PlayingID = FAkAudioInputManager::PostAudioInputEvent(InputEvent, nullptr,
		OnNextBuffer,
		FAkGlobalAudioFormatDelegate::CreateRaw(this, &FAudioMixerInputComponent::GetChannelConfig));

	// TODO Logging
	return PlayingID;
}

void FAudioMixerInputComponent::PostUnregisterGameObject()
{
	auto Device = FAkAudioDevice::Get();
	if (Device != nullptr)
	{
		if (PlayingID != AK_INVALID_PLAYING_ID)
		{
			Device->StopPlayingID(PlayingID);
			PlayingID = AK_INVALID_PLAYING_ID;
		}
	}
}

AkGameObjectID FAudioMixerInputComponent::GetAkGameObjectID() const
{
	return (AkGameObjectID)this;
}
