#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlinkGate.generated.h"

UCLASS(Blueprintable)
class ABlinkGate : public AActor {
    GENERATED_BODY()
public:
    ABlinkGate(const FObjectInitializer& ObjectInitializer);
};

