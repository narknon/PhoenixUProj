#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "Animation/AnimNodeBase.h"
#include "PoseUtilityBipedController.h"
#include "AnimNode_BipedIK.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimNode_BipedIK : public FAnimNode_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseLink BasePose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseUtilityBipedController ControlParameters;
    
    FAnimNode_BipedIK();
};

