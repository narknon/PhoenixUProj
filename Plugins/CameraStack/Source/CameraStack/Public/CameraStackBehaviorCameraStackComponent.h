#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorCameraStackComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackBehaviorCameraStackComponent : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UCameraStackBehaviorCameraStackComponent();
};

