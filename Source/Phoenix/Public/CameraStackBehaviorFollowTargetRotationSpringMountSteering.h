#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorFollowTargetRotationSpring.h"
#include "UObject/NoExportTypes.h"
#include "CameraStackBehaviorFollowTargetRotationSpringMountSteering.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackBehaviorFollowTargetRotationSpringMountSteering : public UCameraStackBehaviorFollowTargetRotationSpring {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InputAlphaInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D SpineDeltaMappedRange;
    
    UCameraStackBehaviorFollowTargetRotationSpringMountSteering();
};

