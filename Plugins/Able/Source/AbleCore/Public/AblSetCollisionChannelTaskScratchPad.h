#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblSetCollisionChannelTaskScratchPad.generated.h"

class UPrimitiveComponent;

UCLASS(Blueprintable, NonTransient)
class UAblSetCollisionChannelTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UPrimitiveComponent>, TEnumAsByte<ECollisionChannel>> PrimitiveToChannelMap;
    
    UAblSetCollisionChannelTaskScratchPad();
};

