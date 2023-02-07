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
#include "AkRtpc.h"
#include "Curves/RichCurve.h"
#include "MovieSceneSection.h"
#include "MovieSceneFloatChannelSerializationHelper.h"

#include "Channels/MovieSceneFloatChannel.h"
#include "MovieSceneAkAudioRTPCSection.generated.h"

/**
* A single floating point section
*/
UCLASS()
class AKAUDIO_API UMovieSceneAkAudioRTPCSection
	: public UMovieSceneSection
{
	GENERATED_BODY()
	UMovieSceneAkAudioRTPCSection(const FObjectInitializer& Init);
	virtual void PostLoad() override;
	virtual void Serialize(FArchive& Ar) override;

public:
	FMovieSceneFloatChannel GetChannel() const {	return RTPCChannel;	}
	float GetStartTime() const;
	float GetEndTime() const;

#if !UE_4_26_OR_LATER
	virtual FMovieSceneEvalTemplatePtr GenerateTemplate() const override;
#endif

	/** @return the name of the RTPC being modified by this track */
	FString GetRTPCName() const { return RTPC ? RTPC->GetName() : Name; }

	/**
	* Sets the name of the RTPC being modified by this track
	*
	* @param InRTPCName The RTPC being modified
	*/
	void SetRTPCName(const FString& InRTPCName) { Name = InRTPCName; }
	void SetRTPC(UAkRtpc* InRTPC) { RTPC = InRTPC; }

#if WITH_EDITOR
#if UE_4_25_OR_LATER
	virtual void PreEditChange(FProperty* PropertyAboutToChange) override;
#else
	virtual void PreEditChange(UProperty* PropertyAboutToChange) override;
#endif
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

protected:
	UPROPERTY(EditAnywhere, Category = "AkAudioRTPC", meta = (NoResetToDefault))
	UAkRtpc* RTPC = nullptr;

	/** Name of the RTPC to modify. */
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category = "AkAudioRTPC", meta = (NoResetToDefault))
	FString Name;

	/** Curve data */
	UPROPERTY()
	FRichCurve FloatCurve;

	// Enabled serialization of RTPCChannel when 4.24 support was added. We will be able to get rid of 
	// FloatChannelSerializationHelper when we remove 4.21 support. Tagging UE_4_21_OR_LATER so we catch
	// this when removing 4.21 support
	UPROPERTY()
	FMovieSceneFloatChannelSerializationHelper FloatChannelSerializationHelper;

	UPROPERTY()
	FMovieSceneFloatChannel RTPCChannel;

private:
#if WITH_EDITOR
	bool IsRTPCNameValid();

	FString PreviousName;
#endif
};
