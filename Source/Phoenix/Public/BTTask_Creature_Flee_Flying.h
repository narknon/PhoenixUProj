#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTTask_Creature_Flee_Flying.generated.h"

UCLASS(Blueprintable)
class UBTTask_Creature_Flee_Flying : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector FleeTargetActorKey;
    
    UBTTask_Creature_Flee_Flying();
};

