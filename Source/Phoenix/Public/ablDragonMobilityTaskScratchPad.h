#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "ablDragonMobilityTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UablDragonMobilityTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UablDragonMobilityTaskScratchPad();
};

