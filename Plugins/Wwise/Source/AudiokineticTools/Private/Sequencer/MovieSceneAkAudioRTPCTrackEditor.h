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

#include "KeyframeTrackEditor.h"
#include "AkUEFeatures.h"
#include "MovieSceneAkAudioRTPCTrack.h"
#include "MovieSceneAkAudioRTPCSection.h"


/**
 * Tools for AkAudioRTPC tracks
 */
class FMovieSceneAkAudioRTPCTrackEditor
	: public FKeyframeTrackEditor<UMovieSceneAkAudioRTPCTrack>
{
public:

	/**
	* Constructor
	*
	* @param InSequencer	The sequencer instance to be used by this tool
	*/
	FMovieSceneAkAudioRTPCTrackEditor(TSharedRef<ISequencer> InSequencer);

	/**
	* Creates an instance of this class.  Called by a sequencer
	*
	* @param OwningSequencer The sequencer instance to be used by this tool
	* @return The new instance of this class
	*/
	static TSharedRef<ISequencerTrackEditor> CreateTrackEditor(TSharedRef<ISequencer> OwningSequencer);

public:

	// ISequencerTrackEditor interface

#if UE_4_23_OR_LATER
	virtual void BuildObjectBindingTrackMenu(FMenuBuilder& MenuBuilder, const TArray<FGuid>& ObjectBindings, const UClass* ObjectClass) override;
#else
	virtual void BuildObjectBindingTrackMenu(FMenuBuilder& MenuBuilder, const FGuid& ObjectBinding, const UClass* ObjectClass) override;
#endif
	virtual void BuildAddTrackMenu(FMenuBuilder& MenuBuilder) override;
	virtual bool SupportsSequence(UMovieSceneSequence* InSequence) const override;

	virtual TSharedRef<ISequencerSection> MakeSectionInterface(UMovieSceneSection& SectionObject, UMovieSceneTrack& Track, FGuid ObjectBinding) override;

	virtual const FSlateBrush* GetIconBrush() const override;

private:

	DECLARE_DELEGATE_RetVal_OneParam(UMovieSceneAkAudioRTPCTrack*, FCreateAkAudioRTPCTrack, UMovieScene*);

	void TryAddAkAudioRTPCTrack(FCreateAkAudioRTPCTrack DoCreateAkAudioRTPCTrack);
};
