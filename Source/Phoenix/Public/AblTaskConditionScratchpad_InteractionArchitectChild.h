#pragma once
#include "CoreMinimal.h"
#include "AblTaskConditionScratchpad.h"
#include "AblTaskConditionScratchpad_InteractionArchitectChild.generated.h"

class UInteractionArchitectAsset;

UCLASS(Blueprintable, NonTransient)
class UAblTaskConditionScratchpad_InteractionArchitectChild : public UAblTaskConditionScratchpad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* InteractionArchitectAsset;
    
    UAblTaskConditionScratchpad_InteractionArchitectChild();
};

