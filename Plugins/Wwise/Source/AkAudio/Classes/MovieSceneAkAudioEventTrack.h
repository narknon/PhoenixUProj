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

#include "MovieSceneAkTrack.h"
#include "IMovieScenePlayer.h"
#include "AkInclude.h"
#include "AkAudioEvent.h"
#if UE_4_26_OR_LATER
#include "Compilation/IMovieSceneTrackTemplateProducer.h"
#else
#include "MovieSceneBackwardsCompatibility.h"
#endif
#include "MovieSceneAkAudioEventTrack.generated.h"

class UMovieSceneAkAudioEventSection;

UCLASS(MinimalAPI)
class UMovieSceneAkAudioEventTrack
	: public UMovieSceneAkTrack
	, public IMovieSceneTrackTemplateProducer
{
	GENERATED_BODY()

public:
	UMovieSceneAkAudioEventTrack()
	{
#if WITH_EDITORONLY_DATA
		SetColorTint(FColor(0, 156, 255, 65));
#endif
	}

	AKAUDIO_API virtual UMovieSceneSection* CreateNewSection() override;
	virtual bool SupportsMultipleRows() const override { return true; }
	virtual bool SupportsType(TSubclassOf<UMovieSceneSection> SectionClass) const override;

	AKAUDIO_API virtual FName GetTrackName() const override;

#if WITH_EDITORONLY_DATA
	AKAUDIO_API virtual FText GetDisplayName() const override;
#endif

	AKAUDIO_API bool AddNewEvent(FFrameNumber Time, UAkAudioEvent* Event, const FString& EventName = FString());

    void WorkUnitChangesDetectedFromSection(UMovieSceneAkAudioEventSection* in_pSection);

protected:
	AKAUDIO_API virtual FMovieSceneEvalTemplatePtr CreateTemplateForSection(const UMovieSceneSection& InSection) const override;
};
