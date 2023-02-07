#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorFocusDistanceToTarget.h"
#include "CameraStackBehaviorFocusDistanceToAnimationTarget.generated.h"

class UCameraStackSecondaryTargetGetter;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorFocusDistanceToAnimationTarget : public UCameraStackBehaviorFocusDistanceToTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackSecondaryTargetGetter* SecondaryTarget;
    
    UCameraStackBehaviorFocusDistanceToAnimationTarget();
};

