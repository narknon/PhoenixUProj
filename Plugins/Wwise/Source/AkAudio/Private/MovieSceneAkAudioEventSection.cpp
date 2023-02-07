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


#include "MovieSceneAkAudioEventSection.h"
#include "AkAudioDevice.h"
#include "AkAudioEvent.h"
#include "AkWaapiClient.h"
#include "MovieSceneAkAudioEventTrack.h"

#include "Misc/Base64.h"
#include "KeyParams.h"
#include "MovieScene.h"
#include "MovieSceneCommonHelpers.h"
#include "MovieSceneSection.h"
#include "MovieSceneAkAudioEventTemplate.h"
#include "Async/Async.h"

DEFINE_LOG_CATEGORY(LogAkAudioEventSection);

/** Default values and helper used by UMovieSceneAkAudioEventSection when querying event information. */
namespace AkAudioEventSectionHelper
{
	// durations are in seconds
	const float DefaultDurationForEventSpecifiedByName = 0.5f;
	const float MinimumDuration = 0.05f;
	const float MaximumDuration = 720000.f;

	int32 GetMaxDurationForFrameRate(FFrameRate FrameRate)
	{
		float Duration = (FrameRate.Denominator * MaximumDuration) / FrameRate.Numerator;
		return static_cast<int32>(FMath::FloorToFloat(Duration));
	}

	FFloatRange GetDuration(UAkAudioEvent* Event, FFrameRate FrameRate)
	{
		if (Event == nullptr)
		{
			// TODO: attempt to determine the length of an AkEvent by its name.
			return FFloatRange(DefaultDurationForEventSpecifiedByName);
		}

		if (Event->GetIsInfinite())
		{
			return FFloatRange(FMath::Min((float)GetMaxDurationForFrameRate(FrameRate), MaximumDuration));
		}

		return FFloatRange(Event->GetMinimumDuration(), TRangeBound<float>::Inclusive(FMath::Clamp(Event->GetMaximumDuration(), MinimumDuration, MaximumDuration)));
	}
}

//===================================================================================================
// Initialization / Destruction
//===================================================================================================

void UMovieSceneAkAudioEventSection::Initialize()
{
    if ((Event != nullptr || EventName != "") && InitState != AkEventSectionState::EUnrecognized)
    {
        UpdateAudioSourceInfo();
        SubscribeToEventChildAddedRemoved();

#if WITH_EDITOR
        RegisterSoundbanksLoadedCallback();

        FAkWaapiClient* pWaapiClient = FAkWaapiClient::Get();
        if (pWaapiClient != nullptr)
        {
            if (InitState == AkEventSectionState::EUninitialized && iChildAddedInitializeSubscriptionID == 0 && pWaapiClient->IsConnected())
            {
                UE_LOG(LogAkAudioEventSection, Warning,
                    TEXT("Failed to initialize Section for Event: %s"),
                    Event == nullptr ? *EventName : *(Event->GetName()));

                //===========================================================
                // Callback 
                //===========================================================
                auto updateAudioSourceInfoCallback = WampEventCallback::CreateLambda([this](uint64_t id, TSharedPtr<FJsonObject> in_UEJsonObject)
                {
                    iCallbackCounter.Increment();
                    AsyncTask(ENamedThreads::GameThread, [this, in_UEJsonObject]()
                    {
                        FScopeLock Lock(&WAAPISection);
                        Initialize();
                        if (InitState == AkEventSectionState::EInitialized)
                        {
                            RequiresUpdate = true;
                        }
                        iCallbackCounter.Decrement();
                    });
                });

                const auto addedUri = ak::wwise::core::object::childAdded;
                TSharedRef<FJsonObject> emptyOptions = MakeShareable(new FJsonObject());
                TSharedPtr<FJsonObject> subscriptionResult = MakeShareable(new FJsonObject());
                //===========================================================
                // Child Added 
                //===========================================================
                pWaapiClient->Subscribe(addedUri, emptyOptions, updateAudioSourceInfoCallback, iChildAddedInitializeSubscriptionID, subscriptionResult);
            }
        }
#endif //WITH_EDITOR
    }
}

void UMovieSceneAkAudioEventSection::BeginDestroy()
{
	/* Wait for WAAPI callbacks to complete */
	while (iCallbackCounter.GetValue() > 0) {}

	UnsubscribeAllWAAPICallbacks();
	if (SoundbanksLoadedHandle.IsValid())
	{
		FAkAudioDevice::Get()->OnSoundbanksLoaded.Remove(SoundbanksLoadedHandle);
		SoundbanksLoadedHandle.Reset();
	}

	FAkAudioDevice::Get()->CancelEventCallbackCookie(EventTracker.Get());

	Super::BeginDestroy();
}

/** Register the callback to trigger when soundbanks are generated. */
void UMovieSceneAkAudioEventSection::RegisterSoundbanksLoadedCallback()
{
    /** First unsubscribe any existing callback. */
    if (SoundbanksLoadedHandle.IsValid())
    {
        FAkAudioDevice::Get()->OnSoundbanksLoaded.Remove(SoundbanksLoadedHandle);
        SoundbanksLoadedHandle.Reset();
    }
    /** Update the Audio source info and indicate that the section requires an update for the editor. */
    if (auto akAudioDevice = FAkAudioDevice::Get())
    {
        SoundbanksLoadedHandle = akAudioDevice->OnSoundbanksLoaded.AddLambda
        ([this]()
        {
            AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this]()
            {
                FScopeLock Lock(&WAAPISection);
                UpdateAudioSourceInfo();
                RequiresUpdate = true;
            });
        });
    }
}

#if WITH_EDITOR
void UMovieSceneAkAudioEventSection::PostEditChangeProperty(struct FPropertyChangedEvent& e)
{
    FName PropertyName = (e.Property != nullptr) ? e.Property->GetFName() : NAME_None;
    if (PropertyName == GET_MEMBER_NAME_CHECKED(UMovieSceneAkAudioEventSection, Event))
    {
        UpdateAkEventInfo();
    }
    Super::PostEditChangeProperty(e);
}
#endif//WITH_EDITOR

//===================================================================================================
// WAAPI Subscriptions
//===================================================================================================

/** Registers a call to update the audio source info when a child is added or removed from in_sParentID */
void UMovieSceneAkAudioEventSection::SubscribeToChildAddedRemoved(FString in_sParentID, uint64& in_iAddedSubID, uint64& in_iRemovedSubID)
{
    FAkWaapiClient* pWaapiClient = FAkWaapiClient::Get();
    if (pWaapiClient != nullptr)
    {
        UnsubscribeWAAPICallback(in_iAddedSubID);
        UnsubscribeWAAPICallback(in_iRemovedSubID);
        //===========================================================
        // Callback 
        //===========================================================
        auto updateAudioSourceInfoCallback = WampEventCallback::CreateLambda([this, in_sParentID](uint64_t id, TSharedPtr<FJsonObject> in_UEJsonObject)
        {
            iCallbackCounter.Increment();
            AsyncTask(ENamedThreads::GameThread, [this, in_sParentID, in_UEJsonObject]()
            {
                auto parentIDString = in_UEJsonObject->GetObjectField(FAkWaapiClient::WAAPIStrings::PARENT)->GetStringField(FAkWaapiClient::WAAPIStrings::ID);
                if (parentIDString.Equals(in_sParentID, ESearchCase::IgnoreCase))
                {
                    FScopeLock Lock(&WAAPISection);
                    UpdateAudioSourceInfo();
                    RequiresUpdate = true;
                }
                iCallbackCounter.Decrement();
            });
        });

        const auto addedUri   = ak::wwise::core::object::childAdded;
        const auto removedUri = ak::wwise::core::object::childRemoved;
        TSharedRef<FJsonObject> emptyOptions = MakeShareable(new FJsonObject());
        TSharedPtr<FJsonObject> subscriptionResult = MakeShareable(new FJsonObject());
        //===========================================================
        // Child Added 
        //===========================================================
        pWaapiClient->Subscribe(addedUri, emptyOptions, updateAudioSourceInfoCallback, in_iAddedSubID, subscriptionResult);
        //===========================================================
        // Child Removed 
        //===========================================================
        subscriptionResult = MakeShareable(new FJsonObject());
        pWaapiClient->Subscribe(removedUri, emptyOptions, updateAudioSourceInfoCallback, in_iRemovedSubID, subscriptionResult);
    }
}

void UMovieSceneAkAudioEventSection::SubscribeToTrimChanges()
{
    UnsubscribeWAAPICallback(iTrimBeginSubscriptionID);
    UnsubscribeWAAPICallback(iTrimEndSubscriptionID);
    //===========================================================
    // Subscribe to TrimBegin and TrimEnd changed events for 
    // new event details.
    //===========================================================
    auto pWaapiClient = FAkWaapiClient::Get();
    if (pWaapiClient != nullptr && pWaapiClient->IsConnected() && AudioSourceInfoIsValid())
    {
        auto updateTrimCallback = WampEventCallback::CreateLambda([this](uint64_t id, TSharedPtr<FJsonObject> in_UEJsonObject)
        {
            iCallbackCounter.Increment();
            AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this, id, in_UEJsonObject]()
            {
                FScopeLock Lock(&WAAPISection);
                UpdateTrimData();
                CheckForWorkunitChanges(true);
                RequiresUpdate = true;
                iCallbackCounter.Decrement();
            });
        });

        //===========================================================
        // TrimEnd 
        //===========================================================
        TSharedPtr<FJsonObject> trimEndSubscriptionResult = MakeShareable(new FJsonObject());
        TSharedRef<FJsonObject> trimEndChangedOptions = MakeShareable(new FJsonObject());
        {
            trimEndChangedOptions->SetStringField(FAkWaapiClient::PropertyChangedStrings::RequiredOptions::OBJECT, MaxDurationSourceID);
            trimEndChangedOptions->SetStringField(FAkWaapiClient::PropertyChangedStrings::RequiredOptions::PROPERTY, FAkWaapiClient::AudioSourceProperties::TRIM_END);
        }

        pWaapiClient->Subscribe(ak::wwise::core::object::propertyChanged, trimEndChangedOptions, updateTrimCallback, iTrimEndSubscriptionID, trimEndSubscriptionResult);

        //===========================================================
        // TrimBegin 
        //===========================================================
        TSharedPtr<FJsonObject> trimBeginSubscriptionResult = MakeShareable(new FJsonObject());
        TSharedRef<FJsonObject> trimBeginChangedOptions = MakeShareable(new FJsonObject());
        {
            trimBeginChangedOptions->SetStringField(FAkWaapiClient::PropertyChangedStrings::RequiredOptions::OBJECT, MaxDurationSourceID);
            trimBeginChangedOptions->SetStringField(FAkWaapiClient::PropertyChangedStrings::RequiredOptions::PROPERTY, FAkWaapiClient::AudioSourceProperties::TRIM_BEGIN);
        }

        pWaapiClient->Subscribe(ak::wwise::core::object::propertyChanged, trimBeginChangedOptions, updateTrimCallback, iTrimBeginSubscriptionID, trimBeginSubscriptionResult);
    }
}

void UMovieSceneAkAudioEventSection::SubscribeToEventChildAddedRemoved()
{        
    UnsubscribeWAAPICallback(iChildAddedSubscriptionID);
    UnsubscribeWAAPICallback(iChildRemovedSubscriptionID);
    auto sParentID = EventGUID.ToString(EGuidFormats::DigitsWithHyphensInBraces);
    SubscribeToChildAddedRemoved(sParentID, iChildAddedSubscriptionID, iChildRemovedSubscriptionID);
    SubscribeToTrimChanges();
}

/** Subscribes to child added and child removed for each of the action targets in the Wwise event that this section triggers. */
void UMovieSceneAkAudioEventSection::SubscribeToEventChildren()
{
    auto pWaapiClient = FAkWaapiClient::Get();
    if (pWaapiClient != nullptr)
    {
        for (int i = 0; i < EventActionSubscriptionIDs.Num(); ++i)
        {
            UnsubscribeWAAPICallback(EventActionSubscriptionIDs[i]);
        }

        EventActionSubscriptionIDs.Empty();

        /* Construct the relevant WAAPI json fields. */
        TArray<TSharedPtr<FJsonValue>> fromID;
        fromID.Add(MakeShareable(new FJsonValueString(EventGUID.ToString(EGuidFormats::DigitsWithHyphensInBraces))));
        AkInt64 returnFlags = (AkInt64)FAkWaapiClient::WAAPIGetReturnOptionFlag::ID | (AkInt64)FAkWaapiClient::WAAPIGetReturnOptionFlag::TYPE;

        TSharedPtr<FJsonObject> select = MakeShareable(new FJsonObject());
        TArray<TSharedPtr<FJsonValue>> selectJsonArray;
        selectJsonArray.Add(MakeShareable(new FJsonValueString(FAkWaapiClient::WAAPIStrings::DESCENDANTS)));
        select->SetArrayField(FAkWaapiClient::WAAPIStrings::SELECT, selectJsonArray);
        TArray<TSharedPtr<FJsonValue>> transform;
        transform.Add(MakeShareable(new FJsonValueObject(select)));

        TSharedPtr<FJsonObject> outJsonResult;
        if (FAkWaapiClient::WAAPIGet(FAkWaapiClient::WAAPIGetFromOption::ID, fromID, returnFlags, outJsonResult, FAkWaapiClient::WAAPIGetTransformOption::SELECT, selectJsonArray))
        {
            if (outJsonResult->HasField(FAkWaapiClient::WAAPIStrings::RETURN))
            {
                TArray<TSharedPtr<FJsonValue>> returnJson = outJsonResult->GetArrayField(FAkWaapiClient::WAAPIStrings::RETURN);
                for (int descendant = 0; descendant < returnJson.Num(); ++descendant)
                {
                    auto pJsonObj = returnJson[descendant]->AsObject();
                    auto descendantID = pJsonObj->GetStringField("id");
                    auto descendantType = pJsonObj->GetStringField("type");

                    if (descendantType.Equals("Action", ESearchCase::IgnoreCase))
                    {
                        /** When we find a child of type action, get the target property */
                        fromID.Empty();
                        fromID.Add(MakeShareable(new FJsonValueString(descendantID)));
                        outJsonResult = MakeShareable(new FJsonObject());
                        TSharedRef<FJsonObject> args = MakeShareable(new FJsonObject());
                        TSharedPtr<FJsonObject> from = MakeShareable(new FJsonObject());
                        from->SetArrayField(FAkWaapiClient::GetFromOptionString(FAkWaapiClient::WAAPIGetFromOption::ID), fromID);
                        args->SetObjectField(FAkWaapiClient::WAAPIStrings::FROM, from);
                        TSharedRef<FJsonObject> options = MakeShareable(new FJsonObject());
                        TArray<TSharedPtr<FJsonValue>> StructJsonArray;
                        StructJsonArray.Add(MakeShareable(new FJsonValueString("@Target")));
                        options->SetArrayField(FAkWaapiClient::WAAPIStrings::RETURN, StructJsonArray);

                        if (pWaapiClient->Call(ak::wwise::core::object::get, args, options, outJsonResult, 500))
                        {
                            if (outJsonResult->HasField(FAkWaapiClient::WAAPIStrings::RETURN))
                            {
                                TArray<TSharedPtr<FJsonValue>> descendantReturnJson = outJsonResult->GetArrayField(FAkWaapiClient::WAAPIStrings::RETURN);
                                auto pDescendantJsonObj = descendantReturnJson[0]->AsObject();
                                if (pDescendantJsonObj->HasField("@Target"))
                                {
                                    /** Subscribe to child added and child removed for the target object. */
                                    auto targetObj = pDescendantJsonObj->GetObjectField("@Target");
                                    auto targetID = targetObj->GetStringField("id");

                                    uint64 addedSubID = 0;
                                    uint64 removedSubID = 0;

                                    SubscribeToChildAddedRemoved(targetID, addedSubID, removedSubID);

                                    if (addedSubID != 0)
                                        EventActionSubscriptionIDs.Add(addedSubID);
                                    if (removedSubID != 0)
                                        EventActionSubscriptionIDs.Add(removedSubID);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void UMovieSceneAkAudioEventSection::UnsubscribeWAAPICallback(uint64& in_iSubID)
{
    if (in_iSubID != 0)
    {
        FScopeLock Lock(&WAAPISection);
        TSharedPtr<FJsonObject> unsubscribeResult = MakeShareable(new FJsonObject());
        FAkWaapiClient* pWaapiClient = FAkWaapiClient::Get();
        if (pWaapiClient != nullptr)
            pWaapiClient->Unsubscribe(in_iSubID, unsubscribeResult, 500, true);
        in_iSubID = 0;
    }
}

void UMovieSceneAkAudioEventSection::UnsubscribeAllWAAPICallbacks()
{
    UnsubscribeWAAPICallback(iChildAddedInitializeSubscriptionID);
    UnsubscribeWAAPICallback(iTrimBeginSubscriptionID);
    UnsubscribeWAAPICallback(iTrimEndSubscriptionID);
    UnsubscribeWAAPICallback(iChildAddedSubscriptionID);
    UnsubscribeWAAPICallback(iChildRemovedSubscriptionID);

    for (int i = 0; i < EventActionSubscriptionIDs.Num(); ++i)
    {
        UnsubscribeWAAPICallback(EventActionSubscriptionIDs[i]);
    }

    EventActionSubscriptionIDs.Empty();
}

//===================================================================================================
// Getters
//===================================================================================================

bool UMovieSceneAkAudioEventSection::EventShouldStopAtSectionEnd() const { return StopAtSectionEnd; }
FGuid UMovieSceneAkAudioEventSection::GetEventGUID() const { return EventGUID; }

const TArray<double>& UMovieSceneAkAudioEventSection::GetAudioSourcePeaks() const { return AudioSourcePeaks; }

/** Returns the number of min max magnitude pairs in the current peaks array. */
const int UMovieSceneAkAudioEventSection::GetNumMinMaxPairs() const { return AudioSourcePeaks.Num() / 2; }

const float	UMovieSceneAkAudioEventSection::GetMaxSourceDuration() const { return MaxSourceDuration; }

const UAkAudioEvent* UMovieSceneAkAudioEventSection::GetEvent() { return Event; }

/** Returns the minimum and maximum durations for the specified Event or EventName. This uses the generated XML data, not WAAPI. */
int32 UMovieSceneAkAudioEventSection::GetMaxEventDuration() const
{
	FFrameRate FrameRate = GetTypedOuter<UMovieScene>()->GetTickResolution();
	auto MaxDuration = AkAudioEventSectionHelper::GetDuration(Event, FrameRate).GetUpperBoundValue();
	return FrameRate.AsFrameNumber(MaxDuration).Value;
}

float UMovieSceneAkAudioEventSection::GetStartTime() const
{
	FFrameRate FrameRate = GetTypedOuter<UMovieScene>()->GetTickResolution();
	return (float)FrameRate.AsSeconds(GetRange().GetLowerBoundValue());
}

float UMovieSceneAkAudioEventSection::GetEndTime() const
{
	FFrameRate FrameRate = GetTypedOuter<UMovieScene>()->GetTickResolution();
	return (float)FrameRate.AsSeconds(GetRange().GetUpperBoundValue());
}

FFloatRange UMovieSceneAkAudioEventSection::GetEventDuration() const
{
	FFrameRate FrameRate = GetTypedOuter<UMovieScene>()->GetTickResolution();
	return AkAudioEventSectionHelper::GetDuration(Event, FrameRate);
}

void UMovieSceneAkAudioEventSection::WAAPIGetPeaks(const char* in_uri,
    TSharedRef<FJsonObject> in_getPeaksArgs,
    TSharedRef<FJsonObject> in_getPeaksOptions,
    TSharedPtr<FJsonObject> in_getPeaksResults)
{
    auto WaapiClient = FAkWaapiClient::Get();
    if (WaapiClient != nullptr)
    {
        if (WaapiClient->Call(in_uri, in_getPeaksArgs, in_getPeaksOptions, in_getPeaksResults, 2000))
        {
            int numPeaksReturned = (int)in_getPeaksResults->GetNumberField(FAkWaapiClient::AudioPeaksStrings::Results::PEAKS_ARRAY_LENGTH);
            if (numPeaksReturned > 0)
            {
                /* Decode the peaks data binary string from WAAPI to the AudioSourcePeaks array. */
                auto peaksBinaryString = in_getPeaksResults->GetArrayField(FAkWaapiClient::AudioPeaksStrings::Results::PEAKS_BINARY)[0]->AsString();
                TArray<uint8> peaksData;
                FBase64::Decode(peaksBinaryString, peaksData);
                int16* peaks = reinterpret_cast<int16*>(peaksData.GetData());
                double maxAbsPeakValue = (double)in_getPeaksResults->GetNumberField(FAkWaapiClient::AudioPeaksStrings::Results::MAX_ABS_VALUE);

                AudioSourcePeaks.Empty();
                for (int p = 0; p < numPeaksReturned * 2; ++p)
                {
                    int16 peakValue = peaks[p];
                    AudioSourcePeaks.Add(peakValue / maxAbsPeakValue);
                }
            }
        }
        else
        {
            UE_LOG(LogAkAudioEventSection, Warning, TEXT("Failed to get audio source peak data from WAAPI"));
        }
    }
}

//===================================================================================================
//===================================================================================================

#if !UE_4_26_OR_LATER
FMovieSceneEvalTemplatePtr UMovieSceneAkAudioEventSection::GenerateTemplate() const
{
	return FMovieSceneAkAudioEventTemplate(this);
}
#endif

/** Associate a new AK audio event with this section. Also updates section time and audio source info. */
void UMovieSceneAkAudioEventSection::SetEvent(UAkAudioEvent* AudioEvent, const FString& Name) 
{
    // Update the event details.
    if (AudioEvent != nullptr)
    {
        Event = AudioEvent;
        EventName = Name.IsEmpty() ? AudioEvent->GetName() : Name;
    }
    else
    {
        EventName = Name;
    }
    
    UpdateAkEventInfo();
}

void UMovieSceneAkAudioEventSection::UpdateAkEventInfo()
{
    UpdateAudioSourceInfo();
    MatchSectionLengthToEventLength();

#if WITH_EDITOR
    RegisterSoundbanksLoadedCallback();
#endif
    SubscribeToEventChildAddedRemoved();
}

void UMovieSceneAkAudioEventSection::MatchSectionLengthToEventLength()
{
    SetRange(TRange<FFrameNumber>(GetRange().GetLowerBoundValue(), GetRange().GetLowerBoundValue() + GetMaxEventDuration()));
}

/** Get the audio peaks data (min max magnitude pairs) for the current MaxDurationSourceID, using WAAPI.
 *  @param in_iNumPeaks - The number of peaks required.
 */
void UMovieSceneAkAudioEventSection::UpdateAudioSourcePeaks(int in_iNumPeaks)
{
    AKASSERT(in_iNumPeaks > 0);
    /* Construct the relevant WAAPI json fields */
	TSharedRef<FJsonObject> getPeaksArgs    = MakeShareable(new FJsonObject());
	TSharedRef<FJsonObject> getPeaksOptions = MakeShareable(new FJsonObject());
	TSharedPtr<FJsonObject> getPeaksResult  = MakeShareable(new FJsonObject());
	getPeaksArgs->SetStringField(FAkWaapiClient::AudioPeaksStrings::Args::OBJECT, MaxDurationSourceID);
	getPeaksArgs->SetNumberField(FAkWaapiClient::AudioPeaksStrings::Args::NUM_PEAKS, in_iNumPeaks);
    getPeaksArgs->SetBoolField(FAkWaapiClient::AudioPeaksStrings::Args::CROSS_CHANNEL_PEAKS, true);

    WAAPIGetPeaks(ak::wwise::core::audioSourcePeaks::getMinMaxPeaksInTrimmedRegion, getPeaksArgs, getPeaksOptions, getPeaksResult);
}

/** Get the audio peaks data (min max magnitude pairs) for the current MaxDurationSourceID, using WAAPI.
*  @param in_iNumPeaks - The number of peaks required.
*  @param in_dtimeFrom - The start time of the time period for which peaks are required
*  @param in_dTimeTo   - The end time of the time period for which peaks are required.
*/
void UMovieSceneAkAudioEventSection::UpdateAudioSourcePeaks(int in_iNumPeaks, double in_dTimeFrom, double in_dTimeTo)
{
    AKASSERT(in_iNumPeaks > 0);
    /* Construct the relevant WAAPI json fields */
    TSharedRef<FJsonObject> getPeaksArgs = MakeShareable(new FJsonObject());
    TSharedRef<FJsonObject> getPeaksOptions = MakeShareable(new FJsonObject());
    TSharedPtr<FJsonObject> getPeaksResult = MakeShareable(new FJsonObject());
    getPeaksArgs->SetStringField(FAkWaapiClient::AudioPeaksStrings::Args::OBJECT, MaxDurationSourceID);
    getPeaksArgs->SetNumberField(FAkWaapiClient::AudioPeaksStrings::Args::NUM_PEAKS, in_iNumPeaks);
    getPeaksArgs->SetNumberField(FAkWaapiClient::AudioPeaksStrings::Args::TIME_FROM, in_dTimeFrom);
    getPeaksArgs->SetNumberField(FAkWaapiClient::AudioPeaksStrings::Args::TIME_TO, in_dTimeTo);
    getPeaksArgs->SetBoolField(FAkWaapiClient::AudioPeaksStrings::Args::CROSS_CHANNEL_PEAKS, true);

    WAAPIGetPeaks(ak::wwise::core::audioSourcePeaks::getMinMaxPeaksInRegion, getPeaksArgs, getPeaksOptions, getPeaksResult);
}

/** Update the trim data for the longest audio source used by the Wwise event that this section triggers. */
void UMovieSceneAkAudioEventSection::UpdateTrimData()
{
    AKASSERT(MaxDurationSourceID != "");

    AkInt64 returnFlag = (AkInt64)FAkWaapiClient::WAAPIGetReturnOptionFlag::AUDIO_SOURCE_TRIM_VALUES;
    TArray<TSharedPtr<FJsonValue>> fromAudioSourceID;
    fromAudioSourceID.Add(MakeShareable(new FJsonValueString(MaxDurationSourceID)));
    TSharedPtr<FJsonObject> trimJsonResult;
    if (FAkWaapiClient::WAAPIGet(FAkWaapiClient::WAAPIGetFromOption::ID, fromAudioSourceID, returnFlag, trimJsonResult))
    {
        TArray<TSharedPtr<FJsonValue>> trimReturnJson = trimJsonResult->GetArrayField(FAkWaapiClient::WAAPIStrings::RETURN);
        auto trimJsonObj = trimReturnJson[0]->AsObject();
        auto trimValuesString = FAkWaapiClient::GetReturnOptionString(FAkWaapiClient::WAAPIGetReturnOptionFlag::AUDIO_SOURCE_TRIM_VALUES);
        auto trimValuesJson = trimJsonObj->GetObjectField(trimValuesString);
        
        /* We only keep track of the TrimBegin value, as the waveform length is calculated using the duration value. */
        TrimBegin = trimValuesJson->GetNumberField(FAkWaapiClient::TrimValuesStrings::TRIM_BEGIN);

        auto TrimEnd = trimValuesJson->GetNumberField(FAkWaapiClient::TrimValuesStrings::TRIM_END);
        MaxSourceDuration = TrimEnd - TrimBegin;
    }
}

/** Use WAAPI to update the MaxDurationSourceID and MaxSourceDuration. */
void UMovieSceneAkAudioEventSection::UpdateAudioSourceInfo()
{
    // Invalidate all audio source info data.
    InvalidateAudioSourceInfo();
    TrimBegin = 0.0f;
    /* Get the GUID of the Wwise event. */
	if (FAkWaapiClient::GetGUIDForObjectOfTypeWithName(EventGUID, "Event", Event == nullptr ? EventName : Event->GetName()))
	{
        // Update the event state in case it had previously been set to EUnrecognised 
        InitState = AkEventSectionState::EUninitialized;
        /* Construct the relevant WAAPI json fields. */
        TArray<TSharedPtr<FJsonValue>> fromID;
        fromID.Add(MakeShareable(new FJsonValueString(EventGUID.ToString(EGuidFormats::DigitsWithHyphensInBraces))));
        AkInt64 returnFlags = (AkInt64)FAkWaapiClient::WAAPIGetReturnOptionFlag::AUDIO_SOURCE_MAX_DURATION_SOURCE |
                                (AkInt64)FAkWaapiClient::WAAPIGetReturnOptionFlag::AUDIO_SOURCE_PLAYBACK_DURATION;
        TSharedPtr<FJsonObject> outJsonResult;
        if (FAkWaapiClient::WAAPIGet(FAkWaapiClient::WAAPIGetFromOption::ID, fromID, returnFlags, outJsonResult))
        {
            /* Update MaxDurationSourceID and MaxSourceDuration from WAAPI return json. */
            TArray<TSharedPtr<FJsonValue>> returnJson = outJsonResult->GetArrayField(FAkWaapiClient::WAAPIStrings::RETURN);
            auto jsonObj = returnJson[0]->AsObject();
            auto maxDurationSourceString = FAkWaapiClient::GetReturnOptionString(FAkWaapiClient::WAAPIGetReturnOptionFlag::AUDIO_SOURCE_MAX_DURATION_SOURCE);
            auto maxDurationSourceJson = jsonObj->GetObjectField(maxDurationSourceString);
            auto newMaxDurationSourceID = maxDurationSourceJson->GetStringField(FAkWaapiClient::WAAPIStrings::ID);
            FGuid maxDurationID;
            FGuid::Parse(newMaxDurationSourceID, maxDurationID);
            if (maxDurationID != EventGUID)
            {
                MaxDurationSourceID = newMaxDurationSourceID;
                MaxSourceDuration = maxDurationSourceJson->GetNumberField(FAkWaapiClient::WAAPIStrings::TRIMMED_DURATION);

                auto playbackDurationString = FAkWaapiClient::GetReturnOptionString(FAkWaapiClient::WAAPIGetReturnOptionFlag::AUDIO_SOURCE_PLAYBACK_DURATION);
                auto playbackDurationJson = jsonObj->GetObjectField(playbackDurationString);
                if (Event != nullptr)
                {
                    Event->SetMinimumDuration(playbackDurationJson->GetNumberField(FAkWaapiClient::PlaybackDurationStrings::MIN));
					Event->SetMaximumDuration(playbackDurationJson->GetNumberField(FAkWaapiClient::PlaybackDurationStrings::MAX));
                }

                UpdateTrimData();

                SubscribeToTrimChanges();
                SubscribeToEventChildren();
            }
            InitState = AkEventSectionState::EInitialized;
            UnsubscribeWAAPICallback(iChildAddedInitializeSubscriptionID);
        }
        else
        {
            UE_LOG(LogAkAudioEventSection, Warning, TEXT("WAAPI call ak.wwise.core.object.get failed"));
        }
        CheckForWorkunitChanges(true);
	}
    else
    {
        //Record that the event is unknown, such that further WAAPI calls will not be made until the event is updated.
        InitState = AkEventSectionState::EUnrecognized;
    }
    RequiresUpdate = true;
}

void UMovieSceneAkAudioEventSection::InvalidateAudioSourceInfo()
{
    AudioSourcePeaks.Empty();
    MaxSourceDuration = -1.0f;
    MaxDurationSourceID = "";
}

bool UMovieSceneAkAudioEventSection::AudioSourceInfoIsValid() const
{
    return MaxDurationSourceID != "" && MaxSourceDuration != -1.0f;
}

void UMovieSceneAkAudioEventSection::CheckForWorkunitChanges(bool in_bNotifyTrack)
{
    /* Check if either of the workunits that contain the event or the longest audio source are dirty.
     * If so, enable the soundbank generation notification in the event section. 
     */
    bool bIsDirty = false;
    bIsDirty |= CheckWorkunitChangesForID(EventGUID);
    if ( ! MaxDurationSourceID.IsEmpty())
    {
        FGuid maxDurationID;
        FGuid::Parse(MaxDurationSourceID, maxDurationID);
        bIsDirty |= CheckWorkunitChangesForID(maxDurationID);
    }
    EventTracker->IsDirty = bIsDirty;
    if (bIsDirty && in_bNotifyTrack)
    {
        if (UMovieSceneAkAudioEventTrack* OwnerTrack = Cast<UMovieSceneAkAudioEventTrack>(GetOuter()))
        {
            OwnerTrack->WorkUnitChangesDetectedFromSection(this);
        }
    }
}

bool UMovieSceneAkAudioEventSection::CheckWorkunitChangesForID(FGuid in_objectGUID)
{
    FGuid workUnitGUID;
    FAkWaapiClient::GetParentOfType(in_objectGUID, workUnitGUID, FAkWaapiClient::WwiseTypeStrings::WORKUNIT);
    TArray<TSharedPtr<FJsonValue>> fromID;
    fromID.Add(MakeShareable(new FJsonValueString(workUnitGUID.ToString(EGuidFormats::DigitsWithHyphensInBraces))));
    AkInt64 returnFlags = (AkInt64)FAkWaapiClient::WAAPIGetReturnOptionFlag::TYPE |
                          (AkInt64)FAkWaapiClient::WAAPIGetReturnOptionFlag::WORKUNIT_IS_DIRTY;
    TSharedPtr<FJsonObject> outJsonResult;
    if (FAkWaapiClient::WAAPIGet(FAkWaapiClient::WAAPIGetFromOption::ID, fromID, returnFlags, outJsonResult))
    {
        TArray<TSharedPtr<FJsonValue>> returnJson = outJsonResult->GetArrayField(FAkWaapiClient::WAAPIStrings::RETURN);
        auto jsonObj = returnJson[0]->AsObject();
        auto typeString = FAkWaapiClient::GetReturnOptionString(FAkWaapiClient::WAAPIGetReturnOptionFlag::TYPE);
        auto objType = jsonObj->GetStringField(typeString);
        AKASSERT(objType.Equals("workunit", ESearchCase::IgnoreCase));
        auto workunitDirtyString = FAkWaapiClient::GetReturnOptionString(FAkWaapiClient::WAAPIGetReturnOptionFlag::WORKUNIT_IS_DIRTY);
        auto workUnitIsDirty = jsonObj->GetBoolField(workunitDirtyString);
        return workUnitIsDirty;
    }
    return false;
}
