#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "ablCastSpellTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UablCastSpellTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UablCastSpellTaskScratchPad();
};

