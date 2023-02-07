#pragma once
#include "CoreMinimal.h"
#include "SceneRigStageRole.h"
#include "SceneRigStageCast.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStageCast {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneRigStageRole> CastMembers;
    
    FSceneRigStageCast();
};

