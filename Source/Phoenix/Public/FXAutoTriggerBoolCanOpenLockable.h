#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBoolLockable.h"
#include "FXAutoTriggerBoolCanOpenLockable.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolCanOpenLockable : public UFXAutoTriggerBoolLockable {
    GENERATED_BODY()
public:
    UFXAutoTriggerBoolCanOpenLockable();
};

