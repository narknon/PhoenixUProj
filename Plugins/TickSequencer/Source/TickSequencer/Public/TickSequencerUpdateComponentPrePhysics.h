#pragma once
#include "CoreMinimal.h"
#include "TickSequencerUpdateComponent.h"
#include "TickSequencerUpdateComponentPrePhysics.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class TICKSEQUENCER_API UTickSequencerUpdateComponentPrePhysics : public UTickSequencerUpdateComponent {
    GENERATED_BODY()
public:
    UTickSequencerUpdateComponentPrePhysics();
};

