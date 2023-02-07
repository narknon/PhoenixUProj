#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblCustomEventListenerTask.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblCustomEventListenerTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UAblCustomEventListenerTask();
};

