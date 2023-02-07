#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Creature_Takeoff.generated.h"

UCLASS(Blueprintable)
class UBTTask_Creature_Takeoff : public UBTTaskNode {
    GENERATED_BODY()
public:
    UBTTask_Creature_Takeoff();
};

