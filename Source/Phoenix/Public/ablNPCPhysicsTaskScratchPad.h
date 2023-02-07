#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "ablNPCPhysicsTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UablNPCPhysicsTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UablNPCPhysicsTaskScratchPad();
};

