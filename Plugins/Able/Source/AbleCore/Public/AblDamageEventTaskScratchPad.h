#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblDamageEventTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABLECORE_API UAblDamageEventTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<float> DamageValues;
    
    UAblDamageEventTaskScratchPad();
};

