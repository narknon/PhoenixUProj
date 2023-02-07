#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Creature_KeepFlying.generated.h"

UCLASS(Blueprintable)
class UBTTask_Creature_KeepFlying : public UBTTaskNode {
    GENERATED_BODY()
public:
    UBTTask_Creature_KeepFlying();
};

