#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "ablExecuteTaskScratchPad.generated.h"

class UablExecuteTaskSubScratchPad;

UCLASS(Blueprintable, NonTransient)
class UablExecuteTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UablExecuteTaskSubScratchPad* SubTaskScratchPad;
    
    UablExecuteTaskScratchPad();
};

