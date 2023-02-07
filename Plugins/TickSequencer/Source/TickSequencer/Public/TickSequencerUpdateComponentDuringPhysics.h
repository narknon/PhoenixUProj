#pragma once
#include "CoreMinimal.h"
#include "TickSequencerUpdateComponent.h"
#include "TickSequencerUpdateComponentDuringPhysics.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class TICKSEQUENCER_API UTickSequencerUpdateComponentDuringPhysics : public UTickSequencerUpdateComponent {
    GENERATED_BODY()
public:
    UTickSequencerUpdateComponentDuringPhysics();
};

