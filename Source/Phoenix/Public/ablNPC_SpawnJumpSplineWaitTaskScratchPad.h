#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "ablNPC_SpawnJumpSplineWaitTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UablNPC_SpawnJumpSplineWaitTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UablNPC_SpawnJumpSplineWaitTaskScratchPad();
};

