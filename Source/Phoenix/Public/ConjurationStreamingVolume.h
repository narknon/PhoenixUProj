#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "ConjurationStreamingVolume.generated.h"

UCLASS(Blueprintable)
class AConjurationStreamingVolume : public AVolume {
    GENERATED_BODY()
public:
    AConjurationStreamingVolume(const FObjectInitializer& ObjectInitializer);
};

