#pragma once
#include "CoreMinimal.h"
#include "TickSequencerUpdateComponent.h"
#include "TickSequencerUpdateComponentPostUpdateWork.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class TICKSEQUENCER_API UTickSequencerUpdateComponentPostUpdateWork : public UTickSequencerUpdateComponent {
    GENERATED_BODY()
public:
    UTickSequencerUpdateComponentPostUpdateWork();
};

