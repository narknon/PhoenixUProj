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
AkSubmixInputComponent.cpp:
=============================================================================*/

#include "AkSubmixInputComponent.h"
#include "AkAudioDevice.h"
#include "AudioMixerDevice.h"

UAkSubmixInputComponent::UAkSubmixInputComponent(const class FObjectInitializer& ObjectInitializer) :
	UAkAudioInputComponent(ObjectInitializer)
{}

Audio::FMixerDevice* UAkSubmixInputComponent::GetAudioMixerDevice()
{
	UWorld* ThisWorld = GetWorld();
	if (!ThisWorld || !ThisWorld->bAllowAudioPlayback || ThisWorld->GetNetMode() == NM_DedicatedServer)
	{
		return nullptr;
	}

	if (FAudioDevice* AudioDevice = ThisWorld->GetAudioDevice().GetAudioDevice())
	{
		if (!AudioDevice->IsAudioMixerEnabled())
		{
			return nullptr;
		}
		else
		{
			return static_cast<Audio::FMixerDevice*>(AudioDevice);
		}
	}
	return nullptr;
}

int32 UAkSubmixInputComponent::PostAssociatedAudioInputEvent()
{
	if (PlayingID == AK_INVALID_PLAYING_ID)
	{
		Audio::FMixerDevice* AudioMixerDevice = GetAudioMixerDevice();
		if (AudioMixerDevice)
		{
			NumChannels = AudioMixerDevice->GetNumDeviceChannels();
			SampleRate = AudioMixerDevice->GetDeviceSampleRate();
			BufferLength = AudioMixerDevice->GetBufferLength();
			SampleBuffer.SetCapacity(2 * BufferLength * NumChannels);
			PoppedSamples.Empty();
			PoppedSamples.AddUninitialized(BufferLength * NumChannels);
			AudioMixerDevice->RegisterSubmixBufferListener(this, SubmixToRecord);
		}
		else
		{
			UE_LOG(LogAkAudio, Log, TEXT("AkSubmixInputComponent (%s): No Audio Mixer Device available, AkSubMixInputComponent cannot work."), *GetOwner()->GetName());
		}

		PlayingID = Super::PostAssociatedAudioInputEvent();
	}
	else
	{
		UE_LOG(LogAkAudio, Log, TEXT("AkSubmixInputComponent (%s): Event was already posted."), *GetOwner()->GetName());
	}
	return PlayingID;
}

void UAkSubmixInputComponent::Stop()
{
	Audio::FMixerDevice* AudioMixerDevice = GetAudioMixerDevice();
	if (AudioMixerDevice)
	{
		AudioMixerDevice->UnregisterSubmixBufferListener(this, SubmixToRecord);
	}
	Super::Stop();
	PlayingID = AK_INVALID_PLAYING_ID;
}

bool UAkSubmixInputComponent::FillSamplesBuffer(uint32 InNumChannels, uint32 InNumSamples, float** InOutBufferToFill)
{
	check(InNumChannels == NumChannels);
	if (SampleBuffer.Num() >= (InNumChannels * InNumSamples))
	{
		auto NumPopped = SampleBuffer.Pop(PoppedSamples.GetData(), InNumChannels * InNumSamples);
		if (NumPopped == InNumChannels * InNumSamples)
		{
			for (uint32 Channel = 0; Channel < InNumChannels; Channel++)
			{
				for (uint32 Sample = 0; Sample < InNumSamples; Sample++)
				{
					InOutBufferToFill[Channel][Sample] = PoppedSamples[((NumChannels * Sample) + Channel)];
				}
			}

			return true;
		}
	}

	for (uint32 Channel = 0; Channel < InNumChannels; Channel++)
	{
		FMemory::Memset(InOutBufferToFill[Channel], 0, InNumSamples * sizeof(float));
	}
	return true;
}

void UAkSubmixInputComponent::GetChannelConfig(AkAudioFormat& AudioFormat)
{
	Audio::FMixerDevice* AudioMixerDevice = GetAudioMixerDevice();
	if (!AudioMixerDevice)
	{
		UE_LOG(LogAkAudio, Log, TEXT("AkSubmixInputComponent (%s): No Audio Mixer Device available, AkSubMixInputComponent cannot work."), *GetOwner()->GetName());
	}

    AudioFormat.uSampleRate = SampleRate;
	switch (NumChannels)
	{
	case 2:
		AudioFormat.channelConfig.SetStandard(AK_SPEAKER_SETUP_STEREO);
		break;
	default:
	case 1:
		NumChannels = 1;
		AudioFormat.channelConfig.SetStandard(AK_SPEAKER_SETUP_MONO);
		break;
	}
}

void UAkSubmixInputComponent::OnNewSubmixBuffer(
	const USoundSubmix* InOwningSubmix,
	float* InAudioData,
	int32				InNumSamples,
	int32				InNumChannels,
	const int32			InSampleRate,
	double				InAudioClock)
{
	check(InNumChannels == NumChannels);
	check(InSampleRate == SampleRate);
	SampleBuffer.Push(InAudioData, InNumSamples);
}