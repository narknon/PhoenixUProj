#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblAddLinearImpulseBaseTask.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAblAddLinearImpulseBaseTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UAblAddLinearImpulseBaseTask();
};

