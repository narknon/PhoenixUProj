#pragma once
#include "CoreMinimal.h"
#include "Evaluation/MovieSceneEvalTemplate.h"
#include "MovieSceneAkAudioEventTemplate.generated.h"

class UMovieSceneAkAudioEventSection;

USTRUCT(BlueprintType)
struct AKAUDIO_API FMovieSceneAkAudioEventTemplate : public FMovieSceneEvalTemplate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMovieSceneAkAudioEventSection* Section;
    
    FMovieSceneAkAudioEventTemplate();
};

