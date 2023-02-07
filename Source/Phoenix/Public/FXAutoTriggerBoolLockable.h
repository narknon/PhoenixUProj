#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "FXAutoTriggerBoolLockable.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolLockable : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UFXAutoTriggerBoolLockable();
};

