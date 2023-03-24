#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConveyorBelt.generated.h"

UCLASS(Blueprintable)
class AConveyorBelt : public AActor {
    GENERATED_BODY()
public:
    AConveyorBelt(const FObjectInitializer& ObjectInitializer);
};

