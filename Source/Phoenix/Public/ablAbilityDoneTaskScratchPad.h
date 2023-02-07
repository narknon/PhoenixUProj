#pragma once
#include "CoreMinimal.h"
#include "AblBranchTaskScratchPad.h"
#include "ablAbilityDoneTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UablAbilityDoneTaskScratchPad : public UAblBranchTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDone;
    
    UablAbilityDoneTaskScratchPad();
};

