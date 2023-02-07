#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_Creature_CanGraze.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_Creature_CanGraze : public UBTDecorator {
    GENERATED_BODY()
public:
    UBTDecorator_Creature_CanGraze();
};

