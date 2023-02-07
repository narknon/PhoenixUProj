#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "ablAttackCollisionTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UablAttackCollisionTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UablAttackCollisionTaskScratchPad();
};

