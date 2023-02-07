#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "EEnemy_AttackThreatState.h"
#include "BTService_Creature_AttackThreat.generated.h"

UCLASS(Blueprintable)
class UBTService_Creature_AttackThreat : public UBTService {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_AttackThreatState AttackThreatState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetActorKey;
    
    UBTService_Creature_AttackThreat();
};

