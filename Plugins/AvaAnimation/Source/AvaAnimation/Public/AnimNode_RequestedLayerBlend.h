#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "Animation/AnimNodeBase.h"
#include "AnimNode_RequestedLayerBlend.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimNode_RequestedLayerBlend : public FAnimNode_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseLink BasePose;
    
    FAnimNode_RequestedLayerBlend();
};

