#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "ablNamedEventTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UablNamedEventTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UablNamedEventTaskScratchPad();
};

