#pragma once
#include "CoreMinimal.h"
#include "ablTurnAdjustTask.h"
#include "ablCreatureAttackTurnAdjustTask.generated.h"

class UCreatureCombatAttackData;

UCLASS(Blueprintable, EditInlineNew)
class UablCreatureAttackTurnAdjustTask : public UablTurnAdjustTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreatureCombatAttackData* AttackData;
    
public:
    UablCreatureAttackTurnAdjustTask();
};

