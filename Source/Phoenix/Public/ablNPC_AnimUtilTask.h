#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EEnemy_Ability.h"
#include "ablNPC_AnimUtilTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablNPC_AnimUtilTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_Ability BranchToAbilityOnRelease;
    
public:
    UablNPC_AnimUtilTask();
};

