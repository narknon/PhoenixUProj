#pragma once
#include "CoreMinimal.h"
#include "Evaluation/MovieSceneEvalTemplate.h"
#include "SceneRigCameraParams.h"
#include "SceneRigCameraSectionTemplate.generated.h"

USTRUCT(BlueprintType)
struct FSceneRigCameraSectionTemplate : public FMovieSceneEvalTemplate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigCameraParams Params;
    
    SCENERIG_API FSceneRigCameraSectionTemplate();
};

