#pragma once
#include "CoreMinimal.h"
#include "Evaluation/MovieSceneEvalTemplate.h"
#include "SceneRigAnimationSectionTemplateParameters.h"
#include "SceneRigAnimationSectionTemplate.generated.h"

USTRUCT(BlueprintType)
struct FSceneRigAnimationSectionTemplate : public FMovieSceneEvalTemplate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAnimationSectionTemplateParameters Params;
    
    SCENERIG_API FSceneRigAnimationSectionTemplate();
};

