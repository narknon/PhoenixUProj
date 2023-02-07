#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Creature_EnableFlyingMovement.generated.h"

UCLASS(Blueprintable)
class UBTTask_Creature_EnableFlyingMovement : public UBTTaskNode {
    GENERATED_BODY()
public:
    UBTTask_Creature_EnableFlyingMovement();
};

