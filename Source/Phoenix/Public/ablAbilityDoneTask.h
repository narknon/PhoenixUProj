#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EEnemyAIState.h"
#include "EEnemy_Ability.h"
#include "ablAbilityDoneTask.generated.h"

class UAblBranchCondition;

UCLASS(Blueprintable, EditInlineNew)
class UablAbilityDoneTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_Ability NextAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDelayBranchIfNextIsIdle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EEnemyAIState> DelayBranchStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblBranchCondition*> Conditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMustPassAllConditions;
    
public:
    UablAbilityDoneTask();
};

