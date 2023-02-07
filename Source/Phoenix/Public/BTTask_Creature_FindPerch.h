#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Creature_FindPerch.generated.h"

UCLASS(Blueprintable)
class UBTTask_Creature_FindPerch : public UBTTaskNode {
    GENERATED_BODY()
public:
    UBTTask_Creature_FindPerch();
};

