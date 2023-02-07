#pragma once
#include "CoreMinimal.h"
#include "TickSequencerUpdateComponentDelegateUpdate.h"
#include "TickSequencerUpdateComponentPostActorTickUpdate.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class TICKSEQUENCER_API UTickSequencerUpdateComponentPostActorTickUpdate : public UTickSequencerUpdateComponentDelegateUpdate {
    GENERATED_BODY()
public:
    UTickSequencerUpdateComponentPostActorTickUpdate();
};

