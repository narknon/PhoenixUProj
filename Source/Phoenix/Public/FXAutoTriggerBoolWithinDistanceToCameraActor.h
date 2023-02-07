#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBoolWithinDistanceToCamera.h"
#include "FXAutoTriggerBoolWithinDistanceToCameraActor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolWithinDistanceToCameraActor : public UFXAutoTriggerBoolWithinDistanceToCamera {
    GENERATED_BODY()
public:
    UFXAutoTriggerBoolWithinDistanceToCameraActor();
};

