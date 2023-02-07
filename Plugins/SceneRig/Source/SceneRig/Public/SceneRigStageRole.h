#pragma once
#include "CoreMinimal.h"
#include "ESceneRigStageRoleType.h"
#include "SceneRigStageRole.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStageRole {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneRigStageRoleType RoleType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RoleIndex;
    
    FSceneRigStageRole();
};

