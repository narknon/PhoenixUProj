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


#include "MovieSceneAkAudioEventTrack.h"
#include "AkAudioDevice.h"

#include "IMovieScenePlayer.h"
#include "MovieScene.h"
#include "MovieSceneAkAudioEventSection.h"
#include "MovieSceneAkAudioEventTemplate.h"

FMovieSceneEvalTemplatePtr UMovieSceneAkAudioEventTrack::CreateTemplateForSection(const UMovieSceneSection& InSection) const
{
#if UE_4_26_OR_LATER
	return FMovieSceneAkAudioEventTemplate(CastChecked<UMovieSceneAkAudioEventSection>(&InSection));
#else
	return InSection.GenerateTemplate();
#endif
}

UMovieSceneSection* UMovieSceneAkAudioEventTrack::CreateNewSection()
{
	return NewObject<UMovieSceneSection>(this, UMovieSceneAkAudioEventSection::StaticClass(), NAME_None, RF_Transactional);
}

bool UMovieSceneAkAudioEventTrack::AddNewEvent(FFrameNumber Time, UAkAudioEvent* Event, const FString& EventName)
{
    UMovieSceneAkAudioEventSection* NewSection = NewObject<UMovieSceneAkAudioEventSection>(this);
	ensure(NewSection);

	NewSection->SetEvent(Event, EventName);
	const auto Duration = NewSection->GetMaxEventDuration();
	NewSection->InitialPlacement(GetAllSections(), Time, Duration, SupportsMultipleRows());
	AddSection(*NewSection);

	return true;
}

void UMovieSceneAkAudioEventTrack::WorkUnitChangesDetectedFromSection(UMovieSceneAkAudioEventSection* in_pSection)
{
    for (auto Section : Sections)
    {
        if (UMovieSceneAkAudioEventSection* AkSection = Cast<UMovieSceneAkAudioEventSection>(Section))
        {
            if (AkSection != in_pSection)
            {
                AkSection->CheckForWorkunitChanges();
            }
        }
    }
}

#if WITH_EDITORONLY_DATA
FText UMovieSceneAkAudioEventTrack::GetDisplayName() const
{
	return NSLOCTEXT("MovieSceneAkAudioEventTrack", "TrackName", "AkAudioEvents");
}
#endif

FName UMovieSceneAkAudioEventTrack::GetTrackName() const
{
	static FName TrackName("AkAudioEvents");
	return TrackName;
}

bool UMovieSceneAkAudioEventTrack::SupportsType(TSubclassOf<UMovieSceneSection> SectionClass) const
{
	return SectionClass == UMovieSceneAkAudioEventSection::StaticClass();
}

