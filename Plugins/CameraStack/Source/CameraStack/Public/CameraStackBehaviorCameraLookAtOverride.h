#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorCamera.h"
#include "CameraStackBehaviorCameraLookAtOverride.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackBehaviorCameraLookAtOverride : public UCameraStackBehaviorCamera {
    GENERATED_BODY()
public:
    UCameraStackBehaviorCameraLookAtOverride();
};

