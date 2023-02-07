#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehavior.h"
#include "CameraStackBehaviorDisableCreatureTickThrottling.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackBehaviorDisableCreatureTickThrottling : public UCameraStackBehavior {
    GENERATED_BODY()
public:
    UCameraStackBehaviorDisableCreatureTickThrottling();
};

