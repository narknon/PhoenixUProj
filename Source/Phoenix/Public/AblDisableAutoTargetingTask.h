#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblDisableAutoTargetingTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblDisableAutoTargetingTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UAblDisableAutoTargetingTask();
};

