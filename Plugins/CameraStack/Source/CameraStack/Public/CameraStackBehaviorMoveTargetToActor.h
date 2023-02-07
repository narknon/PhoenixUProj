#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorMoveTargetToActor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorMoveTargetToActor : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UCameraStackBehaviorMoveTargetToActor();
};

