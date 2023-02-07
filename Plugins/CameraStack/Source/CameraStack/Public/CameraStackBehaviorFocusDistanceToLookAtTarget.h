#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorFocusDistanceToTarget.h"
#include "CameraStackBehaviorFocusDistanceToLookAtTarget.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorFocusDistanceToLookAtTarget : public UCameraStackBehaviorFocusDistanceToTarget {
    GENERATED_BODY()
public:
    UCameraStackBehaviorFocusDistanceToLookAtTarget();
};

