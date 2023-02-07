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

#include "MovieSceneSection.h"
#include "AkInclude.h"
#include "AkAudioEvent.h"
#include "WwiseEventTracking.h"
#include "Dom/JsonObject.h"
#include "MovieSceneAkAudioEventSection.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAkAudioEventSection, Log, All);

class FAkAudioDevice;
struct FWwiseEventTracker;

enum class AkEventSectionState : uint8
{
    EUninitialized = 0,
    EUnrecognized,
    EInitialized
};

/**
* A single floating point section that triggers a Wwise event.
*/
UCLASS(MinimalAPI)
class UMovieSceneAkAudioEventSection : public UMovieSceneSection
{
	GENERATED_BODY()

public:

    void BeginDestroy() override;

    /** Subscribed to child added and child removed for the event ID. When a child is added or removed, UpdateAudioSourceInfo() is called. */
    void SubscribeToEventChildAddedRemoved();

    /** Indicates whether the Wwise event will be re-triggered when the end is reached. */
    bool    ShouldRetriggerEvent() const { return RetriggerEvent; }
    bool    IsValid()              const { return Event != nullptr || !EventName.IsEmpty(); }
    AKAUDIO_API FString GetEventName() const { return (Event == nullptr) ? EventName : Event->GetName(); }
    AKAUDIO_API UAkAudioEvent* GetEvent() const { return Event; }
	bool GetStopAtSectionEnd() const { return StopAtSectionEnd; }

    /** Associate a new AK audio event with this section. Also updates section time and audio source info. */
	void SetEvent(UAkAudioEvent* AudioEvent, const FString& Name);
    /** Use WAAPI to update the MaxDurationSourceID and MaxSourceDuration. */
    AKAUDIO_API void UpdateAudioSourceInfo();
    /** Update the AK event info using the UAkAudioEvent Event member. This should be called when the event is changed. */
    AKAUDIO_API void UpdateAkEventInfo();
    /** Matches the duration of the Unreal Section to that of the Wwise Event. */
    AKAUDIO_API void MatchSectionLengthToEventLength();
    /** Update the audio source info and register the waapi connection callbacks. */
    AKAUDIO_API void Initialize();
    /** Get the audio peaks data (min max magnitude pairs) for the current MaxDurationSourceID, using WAAPI. 
     *  @param in_iNumPeaks - The number of peaks required.  
     */
	AKAUDIO_API void UpdateAudioSourcePeaks(int in_iNumPeaks);
    /** Get the audio peaks data (min max magnitude pairs) for the current MaxDurationSourceID, using WAAPI.
     *  @param in_iNumPeaks - The number of peaks required.
     *  @param in_dtimeFrom - The start time of the time period for which peaks are required
     *  @param in_dTimeTo   - The end time of the time period for which peaks are required.
     */
    AKAUDIO_API void UpdateAudioSourcePeaks(int in_iNumPeaks, double in_dTimeFrom, double in_dTimeTo);

    /** Returns the number of min max magnitude pairs in the current peaks array. */
    AKAUDIO_API const int  GetNumMinMaxPairs() const;
    /** Returns the current peaks array. */
	AKAUDIO_API const TArray<double>& GetAudioSourcePeaks() const;
    /** Returns the duration of the longest audio source that is used in the Wwise event that this section triggers. */
	AKAUDIO_API const float GetMaxSourceDuration() const;

	/** Returns the minimum and maximum durations for the specified Event or EventName. This uses the generated XML data, not WAAPI. */
	AKAUDIO_API FFloatRange GetEventDuration() const;
	

	AKAUDIO_API int32 GetMaxEventDuration() const;
	AKAUDIO_API float GetStartTime() const;
	AKAUDIO_API float GetEndTime() const;

    /** Returns the trim begin value for the Wwise event that this section triggers. */
    float GetTrimBegin() const { return TrimBegin; }
    /** Returns the duration of the scrub snippets that this section produces when scrubbed. 
     *  This can be changed using the ScrubTailLengthMs property. 
     */
    int GetScrubTailLength() const { return ScrubTailLengthMs; }
    /** A structure that tracks Wwise events as they are played, scrubbed, and stopped. */
    TSharedPtr<FWwiseEventTracker> EventTracker = MakeShareable(new FWwiseEventTracker());
    /** Returns true if this section is set to retrigger Wwise events after they finish. Change using the RetriggerEvent property. */
    bool DoesEventRetrigger() const { return RetriggerEvent; }
    /** Resets the audio source information to an uninitialized state. */
    AKAUDIO_API void InvalidateAudioSourceInfo();
    /** Returns true if the audio source information is initialized and valid. */
    AKAUDIO_API bool AudioSourceInfoIsValid() const;

#if !UE_4_26_OR_LATER
    /* UMovieSceneSection interface */
	AKAUDIO_API virtual FMovieSceneEvalTemplatePtr GenerateTemplate() const override;
#endif

    AKAUDIO_API FGuid GetEventGUID() const;

    /** Check if the workunit is dirty. If so, enable the soundbank generation notification in the event section. */
    AKAUDIO_API void CheckForWorkunitChanges(bool in_bNotifyTrack = false);

    bool RequiresUpdate = false;
    AkEventSectionState InitState = AkEventSectionState::EUninitialized;

    /** Unsubscribes from all existing WAAPI subscriptions for this section. */
    void UnsubscribeAllWAAPICallbacks();
#if WITH_EDITOR
    void PostEditChangeProperty(struct FPropertyChangedEvent& e) override;
#endif//WITH_EDITOR
    /** Returns the UAkAudioEvent that this section triggers. */
    AKAUDIO_API const UAkAudioEvent* GetEvent();

    AKAUDIO_API bool EventShouldStopAtSectionEnd() const;

private:
    FCriticalSection WAAPISection;

	/** The AkAudioEvent represented by this section */
	UPROPERTY(EditAnywhere, Category = "AkAudioEvent", meta = (NoResetToDefault))
	UAkAudioEvent* Event = nullptr;

    /* Indicates whether the Wwise event will be re-triggered when the end is reached. */
    UPROPERTY(EditAnywhere, Category = "AkAudioEvent")
    bool RetriggerEvent;

    /* The length, in ms, of scrub snippets */
    UPROPERTY(EditAnywhere, Category = "AkAudioEvent", meta = (ClampMin = "30", ClampMax = "500", UIMin = "30", UIMax = "500"))
    int ScrubTailLengthMs = FWwiseEventTracker::GetScrubTimeMs();

	/** Indicates whether the Wwise event should be stopped when the section stops in the Unreal Sequencer. */
	UPROPERTY(EditAnywhere, Category = "AkAudioEvent")
	bool StopAtSectionEnd = true;

	/** The name of the AkAudioEvent represented by this section */
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category = "AkAudioEvent")
	FString EventName = "";

    FGuid EventGUID;

    /* An array of min-max magnitude pairs from the audio source data. */
	TArray<double> AudioSourcePeaks;

    /** The duration of the longest Wwise source that the Wwise event contains (taking trim into account). */
	UPROPERTY(VisibleAnywhere, Category = "AkAudioEvent")
	float MaxSourceDuration = -1.0f;

    /** The ID of the longest Wwise source that the Wwise event contains. */
	UPROPERTY()
	FString MaxDurationSourceID = "";

    /* A collection of subscription IDs for WAAPI callbacks. */
    uint64 iTrimBeginSubscriptionID = 0;
    uint64 iTrimEndSubscriptionID = 0;
    uint64 iChildAddedSubscriptionID = 0;
    uint64 iChildRemovedSubscriptionID = 0;
    uint64 iChildAddedInitializeSubscriptionID = 0;
    TArray<uint64> EventActionSubscriptionIDs;
    FThreadSafeCounter iCallbackCounter = 0;
    /** Unsubscribes a specfic WAAPI subscription ID. */
    void UnsubscribeWAAPICallback(uint64& in_iSubID);
    
    /* We only keep track of the TrimBegin value (not TrimEnd), as the waveform length is calculated using the duration value. */
    float TrimBegin = 0.0f;
    /** Use WAAPI to get the peak data for the Wwise event, with the given arguments and options. This is called by GetAudioSourcePeaks(). */
    void WAAPIGetPeaks(const char* in_uri, TSharedRef<FJsonObject> in_getPeaksArgs, TSharedRef<FJsonObject> in_getPeaksOptions, TSharedPtr<FJsonObject> in_getPeaksResults);
    /** Update the trim data for the longest audio source used by the Wwise event that this section triggers. */
    void UpdateTrimData();
    /** Subscribe to TrimBegin and TrimEnd properties via WAAPI for the longest audio source that the Wwise event contains. */
    void SubscribeToTrimChanges();
    /** Subscribes to child added and child removed for each of the action targets in the Wwise event that this section triggers. */
    void SubscribeToEventChildren();
    /** Registers a call to update the audio source info when a child is added or removed from in_sParentID */
    void SubscribeToChildAddedRemoved(FString in_sParentID, uint64& in_iAddedSubID, uint64& in_iRemovedSubID);
    /** Gets the containing work unit for the given object ID, and checks whether that workunit is dirty. */
    bool CheckWorkunitChangesForID(FGuid in_objectGUID);

    FDelegateHandle SoundbanksLoadedHandle;
    /** Register the callback to trigger when soundbanks are generated. */
    void RegisterSoundbanksLoadedCallback();
};
