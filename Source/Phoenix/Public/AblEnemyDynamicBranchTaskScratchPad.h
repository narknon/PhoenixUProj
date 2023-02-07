#pragma once
#include "CoreMinimal.h"
#include "AblBranchTaskScratchPad.h"
#include "EEnemy_Ability.h"
#include "AblEnemyDynamicBranchTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblEnemyDynamicBranchTaskScratchPad : public UAblBranchTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EEnemy_Ability TaskState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool BranchCriteriaFromParent;
    
    UAblEnemyDynamicBranchTaskScratchPad();
};

