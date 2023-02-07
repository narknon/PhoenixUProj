#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "GameplayTagContainer.h"
#include "EHiddenTeleportAttackStep.h"
#include "AblEnemyHiddenTeleportAttackTask.generated.h"

class UAblObjectArchitectTagChooser;

UCLASS(Blueprintable, EditInlineNew)
class UAblEnemyHiddenTeleportAttackTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHiddenTeleportAttackStep Step;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer TargetLocationVfxBaseTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblObjectArchitectTagChooser*> TargetLocationVfxTagChoosers;
    
    UAblEnemyHiddenTeleportAttackTask();
};

