#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EEnemy_Ability.h"
#include "ablNPC_SpawnJumpSplineWaitTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablNPC_SpawnJumpSplineWaitTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_Ability BranchToAbilityOnRelease;
    
public:
    UablNPC_SpawnJumpSplineWaitTask();
};

