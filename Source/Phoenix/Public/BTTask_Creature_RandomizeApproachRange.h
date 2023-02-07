#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Creature_RandomizeApproachRange.generated.h"

UCLASS(Blueprintable)
class UBTTask_Creature_RandomizeApproachRange : public UBTTaskNode {
    GENERATED_BODY()
public:
    UBTTask_Creature_RandomizeApproachRange();
};

