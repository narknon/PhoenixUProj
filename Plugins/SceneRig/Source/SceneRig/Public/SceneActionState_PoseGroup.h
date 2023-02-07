#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_PoseGroup.generated.h"

class UPoseGroup;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_PoseGroup : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPoseGroup* CurrentPoseGroup;
    
    USceneActionState_PoseGroup();
};

