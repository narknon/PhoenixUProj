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


#include "AkAudioInputManager.h"
#include "AkAudioDevice.h"
// Register staticly linked AudioInput plugin.
#include <AK/Plugin/AkAudioInputSourceFactory.h>
#if WITH_EDITOR
#include "Editor.h"
#endif
#include "Misc/ScopeLock.h"

/*------------------------------------------------------------------------------------
FAudioInputDelegates
Helper struct that contains an audio samples delegate and an audio format delegate
------------------------------------------------------------------------------------*/

struct FAudioInputDelegates
{
	FAkGlobalAudioInputDelegate AudioSamplesDelegate;
	FAkGlobalAudioFormatDelegate AudioFormatDelegate;
};

/*------------------------------------------------------------------------------------
FAkAudioInputHelpers
------------------------------------------------------------------------------------*/

namespace FAkAudioInputHelpers
{
	static FCriticalSection MapSection;
	static TArray<float*> AudioData = TArray<float*>();
	/* A Map of playing ids to input delegates */
	static TMap<uint32, FAudioInputDelegates> AudioInputDelegates = TMap<uint32, FAudioInputDelegates>();

	static void UpdateDataPointers(AkAudioBuffer* BufferToFill)
	{
		AkUInt32 NumChannels = BufferToFill->NumChannels();
		for (AkUInt32 c = 0; c < NumChannels; ++c)
		{
			AudioData[c] = BufferToFill->GetChannel(c);
		}
	}

	/* The global audio samples callback that searches AudioInputDelegates for
	   the key PlayingID and executes the corresponding delegate*/
	static void GetAudioSamples(AkPlayingID PlayingID, AkAudioBuffer* BufferToFill)
	{
		if (!BufferToFill)
		{
			return;
		}

		BufferToFill->eState = AK_NoMoreData;

		AkUInt32 NumChannels = BufferToFill->NumChannels();
		const AkUInt16 NumFrames = BufferToFill->MaxFrames();

		BufferToFill->uValidFrames = NumFrames;

		FAkGlobalAudioInputDelegate SamplesCallback;

		{
			FScopeLock MapLock(&MapSection);
			auto Delegates = AudioInputDelegates.Find((uint32)PlayingID);
			if (Delegates)
			{
				SamplesCallback = Delegates->AudioSamplesDelegate;
			}
		}
		
		if (SamplesCallback.IsBound())
		{
			UpdateDataPointers(BufferToFill);
			if (SamplesCallback.Execute((int)NumChannels, (int)NumFrames, AudioData.GetData()))
			{
				BufferToFill->eState = AK_DataReady;
			}
		}
		else
		{
			BufferToFill->ZeroPadToMaxFrames();
		}
	}

	/* The global audio format callback that searches AudioInputDelegates for
	the key PlayingID and executes the corresponding delegate*/
	static void GetAudioFormat(AkPlayingID PlayingID, AkAudioFormat& AudioFormat)
	{
		FAkGlobalAudioFormatDelegate FormatCallback;

		{
			FScopeLock MapLock(&MapSection);
			auto Delegates = AudioInputDelegates.Find((uint32)PlayingID);
			if (Delegates)
			{
				FormatCallback = Delegates->AudioFormatDelegate;
			}
		}

		if (FormatCallback.IsBound())
		{
			FormatCallback.Execute(AudioFormat);
		}
		const uint32 NumChannels = AudioFormat.channelConfig.uNumChannels;
		if (AudioData.Max() < (int32)NumChannels)
		{
			AudioData.Reserve(NumChannels);
			AudioData.AddUninitialized(AudioData.GetSlack());
		}
	}

	/**
	* Sets the main callbacks for the Wwise engine audio input plugin.
	*
	*/
	static void SetAkAudioInputCallbacks()
	{
		SetAudioInputCallbacks(&FAkAudioInputHelpers::GetAudioSamples,
							   &FAkAudioInputHelpers::GetAudioFormat,
							   nullptr);
	}
	/* Protects against calling Wwise sound engine SetAudioInputCallbacks function more than once */
	static bool bIsInitialized = false;
	/* Calls the Wwise sound engine SetAudioInputCallbacks function*/
	static void TryInitialize()
	{
		if (!bIsInitialized)
		{
			SetAkAudioInputCallbacks();
			bIsInitialized = true;
		}
#if WITH_EDITOR
		FEditorDelegates::EndPIE.AddLambda([](const bool bIsSimulating) 
		{
			bIsInitialized = false;
		});
#endif
	}

	static void AddAudioInputPlayingID(AkPlayingID PlayingID,
		FAkGlobalAudioInputDelegate AudioSamplesDelegate,
		FAkGlobalAudioFormatDelegate AudioFormatDelegate)
	{
		FScopeLock MapLock(&MapSection);
		AudioInputDelegates.Add((uint32)PlayingID, { AudioSamplesDelegate, AudioFormatDelegate });
	}

	/* Posts an event and associates the AudioSamplesDelegate and AudioFormatDelegate delegates with the resulting playing id. */
	AkPlayingID PostAudioInputEvent(TFunction<AkPlayingID(FAkAudioDevice* AkDevice)> PostEventCall,
							        FAkGlobalAudioInputDelegate AudioSamplesDelegate,
							        FAkGlobalAudioFormatDelegate AudioFormatDelegate)
	{
		TryInitialize();
		AkPlayingID PlayingID = AK_INVALID_PLAYING_ID;
		FAkAudioDevice* AkDevice = FAkAudioDevice::Get();
		if (AkDevice != nullptr)
		{
			PlayingID = PostEventCall(AkDevice);
			if (PlayingID != AK_INVALID_PLAYING_ID)
			{
				AddAudioInputPlayingID(PlayingID, AudioSamplesDelegate, AudioFormatDelegate);
			}
		}
		return PlayingID;
	}

    static void EventCallback(AkCallbackType CallbackType, AkCallbackInfo *CallbackInfo)
	{
		if (CallbackType == AkCallbackType::AK_EndOfEvent)
		{
			AkEventCallbackInfo* EventInfo = (AkEventCallbackInfo*)CallbackInfo;
			if (EventInfo != nullptr)
			{
				uint32 PlayingID = (uint32)EventInfo->playingID;

				{
					FScopeLock MapLock(&MapSection);
					AudioInputDelegates.Remove(PlayingID);
				}
			}
		}
	}
}

/*------------------------------------------------------------------------------------
FAkAudioInputManager
------------------------------------------------------------------------------------*/

AkPlayingID FAkAudioInputManager::PostAudioInputEvent(
    class UAkAudioEvent * Event,
    AActor * Actor,
    FAkGlobalAudioInputDelegate AudioSamplesDelegate,
    FAkGlobalAudioFormatDelegate AudioFormatDelegate
)
{
    return FAkAudioInputHelpers::PostAudioInputEvent([Event, Actor](FAkAudioDevice* AkDevice)
           {
               return AkDevice->PostEvent(Event, Actor, AkCallbackType::AK_EndOfEvent, &FAkAudioInputHelpers::EventCallback);
           }, AudioSamplesDelegate, AudioFormatDelegate);
}


AkPlayingID FAkAudioInputManager::PostAudioInputEvent(
    const FString& EventName,
    AActor * Actor,
    FAkGlobalAudioInputDelegate AudioSamplesDelegate,
    FAkGlobalAudioFormatDelegate AudioFormatDelegate
    )
{
    return FAkAudioInputHelpers::PostAudioInputEvent([EventName, Actor](FAkAudioDevice* AkDevice)
           {
              return AkDevice->PostEvent(EventName, Actor, AkCallbackType::AK_EndOfEvent, &FAkAudioInputHelpers::EventCallback);
           }, AudioSamplesDelegate, AudioFormatDelegate);
}

AkPlayingID FAkAudioInputManager::PostAudioInputEvent(
    const FString& EventName,
    UAkComponent* Component,
    FAkGlobalAudioInputDelegate AudioSamplesDelegate,
    FAkGlobalAudioFormatDelegate AudioFormatDelegate
    )
{
    return FAkAudioInputHelpers::PostAudioInputEvent([EventName, Component](FAkAudioDevice* AkDevice)
           {
              return AkDevice->PostEvent(EventName, Component, AkCallbackType::AK_EndOfEvent, &FAkAudioInputHelpers::EventCallback);
           }, AudioSamplesDelegate, AudioFormatDelegate);
}

AkPlayingID FAkAudioInputManager::PostAudioInputEvent(
	const FString& EventName, 
	AkGameObjectID GameObject, 
	FAkGlobalAudioInputDelegate AudioSamplesDelegate, 
	FAkGlobalAudioFormatDelegate AudioFormatDelegate)
{
	return FAkAudioInputHelpers::PostAudioInputEvent([EventName, GameObject](FAkAudioDevice* AkDevice)
	{			
		TArray<AkExternalSourceInfo> ExternSource;
		return AkDevice->PostEvent(
			EventName, 
			GameObject, 
			AkCallbackType::AK_EndOfEvent, 
			&FAkAudioInputHelpers::EventCallback,
			nullptr,
			ExternSource
		);
	}, AudioSamplesDelegate, AudioFormatDelegate);
}
