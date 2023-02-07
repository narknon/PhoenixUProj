#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTaskScratchPad.h"
#include "CollisionLayerResponseEntry.h"
#include "AblSetCollisionChannelResponseTaskScratchPad.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAblSetCollisionChannelResponseTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCollisionLayerResponseEntry> PreviousCollisionValues;
    
    UAblSetCollisionChannelResponseTaskScratchPad();
};

