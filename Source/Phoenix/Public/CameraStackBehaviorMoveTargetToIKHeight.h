#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorMoveTargetToIKHeight.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackBehaviorMoveTargetToIKHeight : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UCameraStackBehaviorMoveTargetToIKHeight();
};

