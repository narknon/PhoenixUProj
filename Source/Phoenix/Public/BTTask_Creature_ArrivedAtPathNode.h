#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTTask_Creature_ArrivedAtPathNode.generated.h"

UCLASS(Blueprintable)
class UBTTask_Creature_ArrivedAtPathNode : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector PathNodeKey;
    
    UBTTask_Creature_ArrivedAtPathNode();
};

