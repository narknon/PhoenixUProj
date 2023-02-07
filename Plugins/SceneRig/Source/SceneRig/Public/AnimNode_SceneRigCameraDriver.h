#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "Animation/AnimNodeBase.h"
#include "AnimNode_SceneRigCameraDriver.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FAnimNode_SceneRigCameraDriver : public FAnimNode_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseLink BasePose;
    
    FAnimNode_SceneRigCameraDriver();
};

