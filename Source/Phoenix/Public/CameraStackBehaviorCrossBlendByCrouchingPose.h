#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorMultiCrossBlendStandalone.h"
#include "CameraStackBehaviorCrossBlendByCrouchingPose.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackBehaviorCrossBlendByCrouchingPose : public UCameraStackBehaviorMultiCrossBlendStandalone {
    GENERATED_BODY()
public:
    UCameraStackBehaviorCrossBlendByCrouchingPose();
};

