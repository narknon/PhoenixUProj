#pragma once
#include "CoreMinimal.h"
#include "AblBranchTask.h"
#include "EEnemy_Ability.h"
#include "AblEnemyDynamicBranchTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblEnemyDynamicBranchTask : public UAblBranchTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_Ability AbilityState;
    
public:
    UAblEnemyDynamicBranchTask();
};

