#pragma once
#include "CoreMinimal.h"
#include "AlphaBlend.h"
#include "AblAbilityTaskScratchPad.h"
#include "TurnToTaskEntry.h"
#include "AblTurnToTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblTurnToTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTurnToTaskEntry> InProgressTurn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAlphaBlend TurningBlend;
    
    UAblTurnToTaskScratchPad();
};

