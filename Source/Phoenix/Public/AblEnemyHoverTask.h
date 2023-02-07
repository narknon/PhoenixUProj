#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EEnemyHoverTaskMode.h"
#include "AblEnemyHoverTask.generated.h"

class UNiagaraSystem;

UCLASS(Blueprintable, EditInlineNew)
class UAblEnemyHoverTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EEnemyHoverTaskMode> Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoverTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* AttackerLocationVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* TargetLocationVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* AttackLandVFX;
    
public:
    UAblEnemyHoverTask();
};

