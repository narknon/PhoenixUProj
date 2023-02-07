#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorMoveTargetToAttachParent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorMoveTargetToAttachParent : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UCameraStackBehaviorMoveTargetToAttachParent();
};

