#pragma once
#include "CoreMinimal.h"
#include "OverlapEffectsComponent.h"
#include "OverlapAudioComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOverlapAudioComponent : public UOverlapEffectsComponent {
    GENERATED_BODY()
public:
    UOverlapAudioComponent();
};

