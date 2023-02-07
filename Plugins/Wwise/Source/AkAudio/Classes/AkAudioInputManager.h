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


#pragma once

#include "AkInclude.h"
#include "AkAudioDevice.h"
#include "Templates/Function.h"

/*------------------------------------------------------------------------------------
AkAudioInput Delegates
------------------------------------------------------------------------------------*/

DECLARE_DELEGATE_RetVal_ThreeParams(bool, FAkGlobalAudioInputDelegate, uint32, uint32, float**);
DECLARE_DELEGATE_OneParam(FAkGlobalAudioFormatDelegate, AkAudioFormat&);

/*------------------------------------------------------------------------------------
FAkAudioInputManager
------------------------------------------------------------------------------------*/

class AKAUDIO_API FAkAudioInputManager
{
public:

    /**
     * Post an event to ak soundengine
     *
     * @param Event Name of the event to post
     * @param Actor Actor on which to play the event
     * @param AudioSamplesCallback Callback that fills the audio samples buffer
     * @param AudioFormatCallback Callback that sets the audio format
     * @param GainCallback Callback that returns the gain level for the audio input
     * @return ID assigned by ak soundengine
     */
    static AkPlayingID PostAudioInputEvent(
        class UAkAudioEvent * Event,
        AActor * Actor,
        FAkGlobalAudioInputDelegate AudioSamplesDelegate,
        FAkGlobalAudioFormatDelegate AudioFormatDelegate
    );

    /**
     * Post an event to ak soundengine by name
     *
     * @param EventName Name of the event to post
     * @param Actor Actor on which to play the event
     * @param AudioSamplesCallback Callback that fills the audio samples buffer
     * @param AudioFormatCallback Callback that sets the audio format
     * @param GainCallback Callback that returns the gain level for the audio input
     * @return ID assigned by ak soundengine
     */
    static AkPlayingID PostAudioInputEvent(
        const FString& EventName,
        AActor * Actor,
        FAkGlobalAudioInputDelegate AudioSamplesDelegate,
        FAkGlobalAudioFormatDelegate AudioFormatDelegate
    );

    /**
     * Post an event to ak soundengine by name
     *
     * @param EventName Name of the event to post
     * @param Component AkComponent on which to play the event
     * @param AudioSamplesCallback Callback that fills the audio samples buffer
     * @param AudioFormatCallback Callback that sets the audio format
     * @param GainCallback Callback that returns the gain level for the audio input
     * @return ID assigned by ak soundengine
     */
    static AkPlayingID PostAudioInputEvent(
        const FString& EventName,
        UAkComponent* Component,
        FAkGlobalAudioInputDelegate AudioSamplesDelegate,
        FAkGlobalAudioFormatDelegate AudioFormatDelegate
    );

	/**
	 * Post an event to ak soundengine by name
	 *
	 * @param EventName Name of the event to post
	 * @param AkGameObjecton which to play the event
	 * @param AudioSamplesCallback Callback that fills the audio samples buffer
	 * @param AudioFormatCallback Callback that sets the audio format
	 * @param GainCallback Callback that returns the gain level for the audio input
	 * @return ID assigned by ak soundengine
	 */
	static AkPlayingID PostAudioInputEvent(
		const FString& EventName,
		AkGameObjectID GameObject,
		FAkGlobalAudioInputDelegate AudioSamplesDelegate,
		FAkGlobalAudioFormatDelegate AudioFormatDelegate
	);

};