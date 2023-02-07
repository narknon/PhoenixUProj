#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ablEnemy_AUSDecisionTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablEnemy_AUSDecisionTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DecisionBranchChance;
    
public:
    UablEnemy_AUSDecisionTask();
};

