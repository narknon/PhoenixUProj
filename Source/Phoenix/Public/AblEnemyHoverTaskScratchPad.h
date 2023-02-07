#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblEnemyHoverTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblEnemyHoverTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UAblEnemyHoverTaskScratchPad();
};

