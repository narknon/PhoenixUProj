#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "ablNPC_AnimUtilTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UablNPC_AnimUtilTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UablNPC_AnimUtilTaskScratchPad();
};

