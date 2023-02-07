#pragma once
#include "CoreMinimal.h"
#include "AnimNode_ControlRigBase.h"
#include "AnimNode_IKMasterNode.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimNode_IKMasterNode : public FAnimNode_ControlRigBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PoseBlendAlpha;
    
    FAnimNode_IKMasterNode();
};

