#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblRayCastQueryTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblRayCastQueryTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool AsyncProcessed;
    
    UAblRayCastQueryTaskScratchPad();
};

