#pragma once
#include "CoreMinimal.h"
#include "PoseGroupTransition.generated.h"


class UAnimationProvider;
class UPoseGroup;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FPoseGroupTransition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPoseGroup* EndState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* TransitionAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationProvider* TransitionAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBlockLayeredAnimations;
    
    FPoseGroupTransition();
};

