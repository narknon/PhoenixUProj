#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "NPC_AbilityTaskMovementEntry.h"
#include "NPC_AbilityTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UNPC_AbilityTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FNPC_AbilityTaskMovementEntry MoveData;
    
    UNPC_AbilityTaskScratchPad();
};

