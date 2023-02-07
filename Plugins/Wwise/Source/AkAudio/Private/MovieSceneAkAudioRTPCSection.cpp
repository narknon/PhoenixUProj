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


#include "MovieSceneAkAudioRTPCSection.h"
#include "AkAudioDevice.h"
#include "AkCustomVersion.h"
#include "MovieSceneAkAudioRTPCTemplate.h"

#include "Channels/MovieSceneChannelProxy.h"
#include "Channels/MovieSceneChannelEditorData.h"

UMovieSceneAkAudioRTPCSection::UMovieSceneAkAudioRTPCSection(const FObjectInitializer& Init)
	: Super(Init)
{
	FMovieSceneChannelProxyData Channels;

#if WITH_EDITOR
	FMovieSceneChannelMetaData Metadata;
	Metadata.SetIdentifiers("RTPC", NSLOCTEXT("MovieSceneAkAudioRTPCSectionEditorData", "RTPC", "RTPC"));
	Channels.Add(RTPCChannel, Metadata, TMovieSceneExternalValue<float>());
#else
	Channels.Add(RTPCChannel);
#endif

	// Populate the channel proxy - if any of our channels were ever reallocated, we'd need to repopulate the proxy,
	// but since ours are all value member types, we only need to populate in the constructor
	ChannelProxy = MakeShared<FMovieSceneChannelProxy>(MoveTemp(Channels));
}

#if !UE_4_26_OR_LATER
FMovieSceneEvalTemplatePtr UMovieSceneAkAudioRTPCSection::GenerateTemplate() const
{
	return FMovieSceneAkAudioRTPCTemplate(*this);
}
#endif

float UMovieSceneAkAudioRTPCSection::GetStartTime() const
{
	FFrameRate FrameRate = GetTypedOuter<UMovieScene>()->GetTickResolution();
	return (float)FrameRate.AsSeconds(GetRange().GetLowerBoundValue());
}

float UMovieSceneAkAudioRTPCSection::GetEndTime() const
{
	FFrameRate FrameRate = GetTypedOuter<UMovieScene>()->GetTickResolution();
	return (float)FrameRate.AsSeconds(GetRange().GetUpperBoundValue());
}

void UMovieSceneAkAudioRTPCSection::PostLoad()
{
	Super::PostLoad();
	const int32 AkVersion = GetLinkerCustomVersion(FAkCustomVersion::GUID);

	if (AkVersion < FAkCustomVersion::NewRTPCTrackDataContainer)
	{

		if (FloatCurve.GetDefaultValue() != MAX_flt)
		{
			RTPCChannel.SetDefault(FloatCurve.GetDefaultValue());
		}

		RTPCChannel.PreInfinityExtrap = FloatCurve.PreInfinityExtrap;
		RTPCChannel.PostInfinityExtrap = FloatCurve.PostInfinityExtrap;

		TArray<FFrameNumber> Times;
		TArray<FMovieSceneFloatValue> Values;
		Times.Reserve(FloatCurve.GetNumKeys());
		Values.Reserve(FloatCurve.GetNumKeys());

		const FFrameRate LegacyFrameRate = GetLegacyConversionFrameRate();
		const float      Interval = LegacyFrameRate.AsInterval();

		int32 Index = 0;
		for (auto It = FloatCurve.GetKeyIterator(); It; ++It)
		{
			const FRichCurveKey& Key = *It;

			FFrameNumber KeyTime = UpgradeLegacyMovieSceneTime(nullptr, LegacyFrameRate, It->Time);

			FMovieSceneFloatValue NewValue;
			NewValue.Value = Key.Value;
			NewValue.InterpMode = Key.InterpMode;
			NewValue.TangentMode = Key.TangentMode;
			NewValue.Tangent.ArriveTangent = Key.ArriveTangent * Interval;
			NewValue.Tangent.LeaveTangent = Key.LeaveTangent  * Interval;
			ConvertInsertAndSort<FMovieSceneFloatValue>(Index++, KeyTime, NewValue, Times, Values);
		}

		RTPCChannel.Set(Times, Values);
		return;
	}

	FloatChannelSerializationHelper.ToFloatChannel(RTPCChannel);
}

void UMovieSceneAkAudioRTPCSection::Serialize(FArchive& Ar)
{
	FloatChannelSerializationHelper = RTPCChannel;
	Ar.UsingCustomVersion(FAkCustomVersion::GUID);
	Super::Serialize(Ar);
}

#if WITH_EDITOR
#if UE_4_25_OR_LATER
void UMovieSceneAkAudioRTPCSection::PreEditChange(FProperty* PropertyAboutToChange)
#else
void UMovieSceneAkAudioRTPCSection::PreEditChange(UProperty* PropertyAboutToChange)
#endif
{
	PreviousName = Name;
}

void UMovieSceneAkAudioRTPCSection::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	const FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(UMovieSceneAkAudioRTPCSection, Name))
	{
		if (!IsRTPCNameValid())
		{
			Name = PreviousName;
		}
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

bool UMovieSceneAkAudioRTPCSection::IsRTPCNameValid()
{
	return !Name.IsEmpty();
}
#endif
