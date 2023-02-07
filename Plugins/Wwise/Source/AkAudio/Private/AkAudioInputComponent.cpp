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
AkAudioInputComponent.cpp:
=============================================================================*/

#include "AkAudioInputComponent.h"
#include "AkAudioDevice.h"
#include "AkAudioEvent.h"

UAkAudioInputComponent::UAkAudioInputComponent(const class FObjectInitializer& ObjectInitializer) :
    Super(ObjectInitializer)
{}

int32 UAkAudioInputComponent::PostAssociatedAudioInputEvent()
{
	AudioInputDelegate = FAkGlobalAudioInputDelegate::CreateLambda(
		[this](uint32 NumChannels, uint32 NumSamples, float** BufferToFill) -> bool
		{
			return FillSamplesBuffer(NumChannels, NumSamples, BufferToFill);
		});

	AudioFormatDelegate = FAkGlobalAudioFormatDelegate::CreateLambda([this](AkAudioFormat& AudioFormat)
	{
		return GetChannelConfig(AudioFormat);
	});

	AkPlayingID PlayingID = FAkAudioInputManager::PostAudioInputEvent(
		GET_AK_EVENT_NAME(AkAudioEvent, EventName), this, AudioInputDelegate, AudioFormatDelegate);

	if (PlayingID != AK_INVALID_PLAYING_ID)
	{
		CurrentlyPlayingIDs.Add(PlayingID);
	}
	return PlayingID;
}

void UAkAudioInputComponent::PostUnregisterGameObject()
{
	if (AudioInputDelegate.IsBound())
	{
		AudioInputDelegate.Unbind();
	}

	if (AudioFormatDelegate.IsBound())
	{
		AudioFormatDelegate.Unbind();
	}

	auto Device = FAkAudioDevice::Get();
	if (Device != nullptr)
	{
		for (int i = 0; i < CurrentlyPlayingIDs.Num(); ++i)
		{
			Device->StopPlayingID(CurrentlyPlayingIDs[i]);
		}
	}
	CurrentlyPlayingIDs.Empty();
}