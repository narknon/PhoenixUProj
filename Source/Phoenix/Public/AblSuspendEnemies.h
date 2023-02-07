#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblSuspendEnemies.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSuspendEnemies : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableSuspendHideForCombatPlants;
    
public:
    UAblSuspendEnemies();
};

