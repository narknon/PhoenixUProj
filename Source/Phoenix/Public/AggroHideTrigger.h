#pragma once
#include "CoreMinimal.h"
#include "HideTrigger.h"
#include "AggroHideTrigger.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API AAggroHideTrigger : public AHideTrigger {
    GENERATED_BODY()
public:
    AAggroHideTrigger(const FObjectInitializer& ObjectInitializer);
};

