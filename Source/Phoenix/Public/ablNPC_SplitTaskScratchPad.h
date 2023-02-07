#pragma once
#include "CoreMinimal.h"
#include "AblBranchTaskScratchPad.h"
#include "ablNPC_SplitTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UablNPC_SplitTaskScratchPad : public UAblBranchTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDone;
    
    UablNPC_SplitTaskScratchPad();
};

