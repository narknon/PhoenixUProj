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


#include "MovieSceneAkAudioRTPCTrack.h"
#include "AkAudioDevice.h"

#include "IMovieScenePlayer.h"
#include "MovieSceneCommonHelpers.h"

#include "MovieSceneAkAudioRTPCSection.h"

#include "MovieSceneAkAudioRTPCTemplate.h"

FMovieSceneEvalTemplatePtr UMovieSceneAkAudioRTPCTrack::CreateTemplateForSection(const UMovieSceneSection& InSection) const
{
#if UE_4_26_OR_LATER
	return FMovieSceneAkAudioRTPCTemplate(*CastChecked<UMovieSceneAkAudioRTPCSection>(&InSection));
#else
	return InSection.GenerateTemplate();
#endif
}

UMovieSceneSection* UMovieSceneAkAudioRTPCTrack::CreateNewSection()
{
	return NewObject<UMovieSceneSection>(this, UMovieSceneAkAudioRTPCSection::StaticClass(), NAME_None, RF_Transactional);
}

#if WITH_EDITORONLY_DATA
FText UMovieSceneAkAudioRTPCTrack::GetDisplayName() const
{
	auto AllSections = GetAllSections();
	FString DisplayName("AkAudioRTPC");
	if (AllSections.Num() > 0)
	{
		UMovieSceneAkAudioRTPCSection* RTPCSection = CastChecked<UMovieSceneAkAudioRTPCSection>(AllSections[0]);
		DisplayName += TEXT(" - ") + RTPCSection->GetRTPCName();
	}

	if (AllSections.Num() > 1)
	{
		DisplayName += TEXT(" and more.");
	}

	return FText::FromString(DisplayName);
}
#endif

FName UMovieSceneAkAudioRTPCTrack::GetTrackName() const
{
	const auto Section = CastChecked<UMovieSceneAkAudioRTPCSection>(MovieSceneHelpers::FindNearestSectionAtTime(Sections, 0));
	return (Section != nullptr) ? FName(*Section->GetRTPCName()) : FName(NAME_None);
}

bool UMovieSceneAkAudioRTPCTrack::SupportsType(TSubclassOf<UMovieSceneSection> SectionClass) const
{
	return SectionClass == UMovieSceneAkAudioRTPCSection::StaticClass();
}

