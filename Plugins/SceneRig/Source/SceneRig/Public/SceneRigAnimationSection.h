#pragma once
#include "CoreMinimal.h"
#include "MovieSceneSection.h"
#include "SceneRigAnimationParams.h"
#include "SceneRigAnimationSection.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class USceneRigAnimationSection : public UMovieSceneSection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigAnimationParams Params;
    
    USceneRigAnimationSection();
};

