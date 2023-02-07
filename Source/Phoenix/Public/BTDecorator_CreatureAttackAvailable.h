#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTDecorator_CreatureAttackAvailable.generated.h"

class UCreatureCombatAttackData;

UCLASS(Blueprintable)
class UBTDecorator_CreatureAttackAvailable : public UBTDecorator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreatureCombatAttackData* AttackData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetLocationKey;
    
    UBTDecorator_CreatureAttackAvailable();
};

