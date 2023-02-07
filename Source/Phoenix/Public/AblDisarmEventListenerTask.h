#pragma once
#include "CoreMinimal.h"
#include "AblCustomEventListenerOnceTask.h"
#include "AblDisarmEventListenerTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblDisarmEventListenerTask : public UAblCustomEventListenerOnceTask {
    GENERATED_BODY()
public:
    UAblDisarmEventListenerTask();
};

