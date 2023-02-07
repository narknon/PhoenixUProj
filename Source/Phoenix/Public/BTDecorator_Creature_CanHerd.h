#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_Creature_CanHerd.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_Creature_CanHerd : public UBTDecorator {
    GENERATED_BODY()
public:
    UBTDecorator_Creature_CanHerd();
};

