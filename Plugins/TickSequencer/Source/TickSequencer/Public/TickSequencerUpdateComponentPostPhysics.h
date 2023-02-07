#pragma once
#include "CoreMinimal.h"
#include "TickSequencerUpdateComponent.h"
#include "TickSequencerUpdateComponentPostPhysics.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class TICKSEQUENCER_API UTickSequencerUpdateComponentPostPhysics : public UTickSequencerUpdateComponent {
    GENERATED_BODY()
public:
    UTickSequencerUpdateComponentPostPhysics();
};

