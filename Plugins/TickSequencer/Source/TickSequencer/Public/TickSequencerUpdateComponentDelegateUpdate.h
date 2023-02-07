#pragma once
#include "CoreMinimal.h"
#include "TickSequencerUpdateComponent.h"
#include "TickSequencerUpdateComponentDelegateUpdate.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class TICKSEQUENCER_API UTickSequencerUpdateComponentDelegateUpdate : public UTickSequencerUpdateComponent {
    GENERATED_BODY()
public:
    UTickSequencerUpdateComponentDelegateUpdate();
};

