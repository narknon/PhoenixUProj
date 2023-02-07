#pragma once
#include "CoreMinimal.h"
#include "ablMotionAdjustTask.h"
#include "ablCreatureAttackMotionAdjustTask.generated.h"

class UCreatureCombatAttackData;

UCLASS(Blueprintable, EditInlineNew)
class UablCreatureAttackMotionAdjustTask : public UablMotionAdjustTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreatureCombatAttackData* AttackData;
    
public:
    UablCreatureAttackMotionAdjustTask();
};

