#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "Animation/AnimNodeBase.h"
#include "AnimNode_AmbientFacial.generated.h"

class UAimEyesData;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimNode_AmbientFacial : public FAnimNode_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseLink BasePose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAimEyesData* AimEyesData;
    
    FAnimNode_AmbientFacial();
};

