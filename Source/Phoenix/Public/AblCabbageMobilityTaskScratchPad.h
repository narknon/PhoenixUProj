#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "UObject/NoExportTypes.h"
#include "AblCabbageMobilityTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblCabbageMobilityTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsDone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector VectorAwayFromAttacked;
    
    UAblCabbageMobilityTaskScratchPad();
};

