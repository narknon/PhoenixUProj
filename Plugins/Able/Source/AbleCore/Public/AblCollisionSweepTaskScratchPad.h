#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblCollisionSweepTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblCollisionSweepTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTransform SourceTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool AsyncProcessed;
    
    UAblCollisionSweepTaskScratchPad();
};

