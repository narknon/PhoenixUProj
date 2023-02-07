#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorMatchTargetRotation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorMatchTargetRotation : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MatchYaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MatchPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MatchRoll;
    
    UCameraStackBehaviorMatchTargetRotation();
};

