#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "BTCustomActionTaskEntry.h"
#include "AblBTCustomActionTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblBTCustomActionTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FBTCustomActionTaskEntry> InProgressMessage;
    
    UAblBTCustomActionTaskScratchPad();
};

