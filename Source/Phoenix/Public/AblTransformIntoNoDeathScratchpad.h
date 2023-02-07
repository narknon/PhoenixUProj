#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblTransformIntoNoDeathScratchpad.generated.h"

class AActor;

UCLASS(Blueprintable, NonTransient)
class UAblTransformIntoNoDeathScratchpad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* SpawnedCreature;
    
    UAblTransformIntoNoDeathScratchpad();
};

