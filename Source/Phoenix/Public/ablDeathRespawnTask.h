#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ablDeathRespawnTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablDeathRespawnTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UablDeathRespawnTask();
};

