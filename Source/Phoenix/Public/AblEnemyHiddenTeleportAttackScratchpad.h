#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblEnemyHiddenTeleportAttackScratchpad.generated.h"

class UEnemyHiddenTeleportAttackComponent;

UCLASS(Blueprintable, NonTransient)
class UAblEnemyHiddenTeleportAttackScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyHiddenTeleportAttackComponent* EnemyHiddenTeleportAttackComp;
    
    UAblEnemyHiddenTeleportAttackScratchpad();
};

