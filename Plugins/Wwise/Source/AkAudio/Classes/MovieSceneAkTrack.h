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

#include "MovieScene.h"
#include "MovieSceneTrack.h"
#include "AkUEFeatures.h"

#if !UE_4_25_OR_LATER
#include "IMovieSceneTrackInstance.h"
#endif
#include "MovieSceneAkTrack.generated.h"


/**
 * Handles manipulation of an Ak track in a movie scene
 */
UCLASS(abstract, MinimalAPI)
class UMovieSceneAkTrack 
	: public UMovieSceneTrack
{
	GENERATED_BODY()

public:

	/** begin UMovieSceneTrack interface */
	
	virtual void RemoveAllAnimationData() override { Sections.Empty(); }
	virtual bool HasSection(const UMovieSceneSection& Section) const override { return Sections.Contains(&Section); }
	virtual void AddSection(UMovieSceneSection& Section) override { Sections.Add(&Section); }
	virtual void RemoveSection(UMovieSceneSection& Section) override { Sections.Remove(&Section); }
	virtual bool IsEmpty() const override { return Sections.Num() == 0; }
	virtual const TArray<UMovieSceneSection*>& GetAllSections() const override { return Sections; }

	/** end UMovieSceneTrack interface */

	void SetIsAMasterTrack(bool AMasterTrack) { bIsAMasterTrack = AMasterTrack; }
	bool IsAMasterTrack() const { return bIsAMasterTrack; }

protected:

	/** All the sections in this track */
	UPROPERTY()
	TArray<UMovieSceneSection*> Sections;

	UPROPERTY()
	uint32 bIsAMasterTrack : 1;
};
