#pragma once
#include "CoreMinimal.h"
#include "TickSequencerUpdateComponentDelegateUpdate.h"
#include "TickSequencerUpdateComponentPreActorTickUpdate.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class TICKSEQUENCER_API UTickSequencerUpdateComponentPreActorTickUpdate : public UTickSequencerUpdateComponentDelegateUpdate {
    GENERATED_BODY()
public:
    UTickSequencerUpdateComponentPreActorTickUpdate();
};

