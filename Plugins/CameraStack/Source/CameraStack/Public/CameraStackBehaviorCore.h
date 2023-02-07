#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehavior.h"
#include "CameraStackBehaviorCore.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorCore : public UCameraStackBehavior {
    GENERATED_BODY()
public:
    UCameraStackBehaviorCore();
};

