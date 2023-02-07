#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "Engine/EngineTypes.h"
#include "AblMovementModeTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblMovementModeTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMovementMode> OriginalMovementMode;
    
    UAblMovementModeTaskScratchPad();
};

