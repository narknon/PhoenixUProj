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

#include "AkAudioDevice.h"
#include "AkComponent.h"
#include "UObject/ObjectMacros.h"

/** This can be used to track a Wwise event as it is triggered and stopped.
 *  Maintains a collection of playing IDs and a collection of IDs that have scheduled stop calls.
 *  Also maintains a collection of Vector2Ds that indicate the history of start times and durations
 *  of event retriggers.
 */
struct AKAUDIO_API FWwiseEventTracker
{
	static int GetScrubTimeMs() { return 100; }

	/** Callback receieved at various points during lifetime Wwise event. 
	 *  The FWwiseEventTracker is stored in the AkCallbackInfo as pCookie.
	 */
	static void PostEventCallbackHandler(AkCallbackType in_eType, AkCallbackInfo* in_pCallbackInfo);

	void RemoveScheduledStop(AkPlayingID InID);

	void RemovePlayingID(AkPlayingID InID);

	void TryAddPlayingID(const AkPlayingID& PlayingID);

	void EmptyPlayingIDs();

	void EmptyScheduledStops();

	bool PlayingIDHasScheduledStop(AkPlayingID InID);

	void AddScheduledStop(AkPlayingID InID);

	bool IsDirty = false;

	bool IsPlaying()        const { FScopeLock autoLock(&PlayingIDsLock); return PlayingIDs.Num()     > 0; }
	bool HasScheduledStop() const { FScopeLock autoLock(&ScheduledStopsLock); return ScheduledStops.Num() > 0; }
	float GetClipDuration() const { return ClipEndTime - ClipStartTime; }
	
	TArray<AkPlayingID> PlayingIDs;
	TArray<AkPlayingID> ScheduledStops;
	FFloatRange         EventDuration;
	FString             EventName;
	UAkAudioEvent*      Event;
	mutable FCriticalSection    PlayingIDsLock;
	mutable FCriticalSection    ScheduledStopsLock;
	float               ClipStartTime                      = 0.0f;
	float               ClipEndTime                        = 0.0f;
	int                 ScrubTailLengthMs                  = GetScrubTimeMs();
	float               PreviousEventStartTime             = -1.0f;
	float               PreviousPlayingTime                = -1.0f;
	float               CurrentDurationEstimation          = -1.0f;
	float               CurrentDurationProportionRemaining = 1.0f;
	bool                bStopAtSectionEnd                  = true;
};

/** A collection of helper functions for triggering tracked Wwise events */
namespace WwiseEventTriggering
{
	AKAUDIO_API TArray<AkPlayingID, TInlineAllocator<16>> GetPlayingIds(FWwiseEventTracker& EventTracker);

	AKAUDIO_API void LogDirtyPlaybackWarning();

	AKAUDIO_API void StopAllPlayingIDs(FAkAudioDevice* AudioDevice, FWwiseEventTracker& EventTracker);

	AKAUDIO_API AkPlayingID PostEventOnDummyObject(FAkAudioDevice* AudioDevice, FWwiseEventTracker& EventTracker, float CurrentTime);

	AKAUDIO_API AkPlayingID PostEvent(UObject* Object, FAkAudioDevice* AudioDevice, FWwiseEventTracker& EventTracker, float CurrentTime);

	AKAUDIO_API void StopEvent(FAkAudioDevice* AudioDevice, AkPlayingID InPlayingID, FWwiseEventTracker* EventTracker);

	AKAUDIO_API void TriggerStopEvent(FAkAudioDevice* AudioDevice, FWwiseEventTracker& EventTracker, AkPlayingID PlayingID);

	AKAUDIO_API void ScheduleStopEventsForCurrentlyPlayingIDs(FAkAudioDevice* AudioDevice, FWwiseEventTracker& EventTracker);

	/** Trigger and EventTracker's Wwise event and schedule an accompanying stop event. */
	AKAUDIO_API void TriggerScrubSnippetOnDummyObject(FAkAudioDevice* AudioDevice, FWwiseEventTracker& EventTracker);

	/** Trigger and EventTracker's Wwise event and schedule an accompanying stop event. */
	AKAUDIO_API void TriggerScrubSnippet(UObject* Object, FAkAudioDevice* AudioDevice, FWwiseEventTracker& EventTracker);

	AKAUDIO_API void SeekOnEvent(UObject* Object, FAkAudioDevice* AudioDevice, AkReal32 in_fPercent, FWwiseEventTracker& EventTracker, AkPlayingID InPlayingID);

	AKAUDIO_API void SeekOnEvent(UObject* Object, FAkAudioDevice* AudioDevice, AkReal32 in_fPercent, FWwiseEventTracker& EventTracker);

	AKAUDIO_API void SeekOnEventWithDummyObject(FAkAudioDevice* AudioDevice, AkReal32 ProportionalTime, FWwiseEventTracker& EventTracker, AkPlayingID InPlayingID);

	AKAUDIO_API void SeekOnEventWithDummyObject(FAkAudioDevice* AudioDevice, AkReal32 ProportionalTime, FWwiseEventTracker& EventTracker);
}
