#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EEnemy_Ability.h"
#include "AblBranchConditionEnemyAbilitySupported.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionEnemyAbilitySupported : public UAblBranchCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_Ability Ability;
    
    UAblBranchConditionEnemyAbilitySupported();
};

