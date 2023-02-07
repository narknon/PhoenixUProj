#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblCollisionQueryTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblCollisionQueryTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTransform QueryTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool AsyncProcessed;
    
    UAblCollisionQueryTaskScratchPad();
};

