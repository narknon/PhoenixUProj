#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehavior.h"
#include "CameraStackBehaviorNoOp.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorNoOp : public UCameraStackBehavior {
    GENERATED_BODY()
public:
    UCameraStackBehaviorNoOp();
};

