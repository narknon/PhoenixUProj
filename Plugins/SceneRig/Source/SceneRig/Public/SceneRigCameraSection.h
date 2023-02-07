#pragma once
#include "CoreMinimal.h"
#include "MovieSceneSection.h"
#include "SceneRigCameraParams.h"
#include "SceneRigCameraSection.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class USceneRigCameraSection : public UMovieSceneSection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigCameraParams Params;
    
    USceneRigCameraSection();
};

