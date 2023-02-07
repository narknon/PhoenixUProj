#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "UObject/NoExportTypes.h"
#include "AblBallisticBounceBackTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblBallisticBounceBackTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector VectorAwayFromAttacked;
    
    UAblBallisticBounceBackTaskScratchPad();
};

