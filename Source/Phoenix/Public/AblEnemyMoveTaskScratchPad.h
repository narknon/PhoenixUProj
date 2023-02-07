#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "EnemyMoveTaskEntry.h"
#include "AblEnemyMoveTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblEnemyMoveTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEnemyMoveTaskEntry MoveData;
    
    UAblEnemyMoveTaskScratchPad();
};

