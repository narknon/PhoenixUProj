#pragma once
#include "CoreMinimal.h"
#include "Evaluation/MovieSceneEvalTemplate.h"
#include "MovieSceneAkAudioRTPCTemplate.generated.h"

class UMovieSceneAkAudioRTPCSection;

USTRUCT(BlueprintType)
struct AKAUDIO_API FMovieSceneAkAudioRTPCTemplate : public FMovieSceneEvalTemplate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMovieSceneAkAudioRTPCSection* Section;
    
    FMovieSceneAkAudioRTPCTemplate();
};

