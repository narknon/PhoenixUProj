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

#include "CoreMinimal.h"
#include "AkUEFeatures.h"
#include "UObject/ObjectMacros.h"
#include "Evaluation/MovieSceneEvalTemplate.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "MovieSceneAkAudioRTPCTemplate.generated.h"


class UMovieSceneAkAudioRTPCSection;

struct FMovieSceneAkAudioRTPCSectionData
{
	FMovieSceneAkAudioRTPCSectionData() {}

	FMovieSceneAkAudioRTPCSectionData(const UMovieSceneAkAudioRTPCSection& Section);

	FString RTPCName;

	FMovieSceneFloatChannel RTPCChannel;
};


USTRUCT()
struct AKAUDIO_API FMovieSceneAkAudioRTPCTemplate
	: public FMovieSceneEvalTemplate
{
	GENERATED_BODY()

	FMovieSceneAkAudioRTPCTemplate() {}

	FMovieSceneAkAudioRTPCTemplate(const UMovieSceneAkAudioRTPCSection& InSection);

	virtual void Evaluate(const FMovieSceneEvaluationOperand& Operand, const FMovieSceneContext& Context, const FPersistentEvaluationData& PersistentData, FMovieSceneExecutionTokens& ExecutionTokens) const override;

	virtual UScriptStruct& GetScriptStructImpl() const override { return *StaticStruct(); }

	virtual void Setup(FPersistentEvaluationData& PersistentData, IMovieScenePlayer& Player) const override;
	virtual void SetupOverrides() override { EnableOverrides(RequiresSetupFlag); }

	UPROPERTY()
	const UMovieSceneAkAudioRTPCSection* Section = nullptr;
};
