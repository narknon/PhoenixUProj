#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoilerPipe.generated.h"

UCLASS(Blueprintable)
class ABoilerPipe : public AActor {
    GENERATED_BODY()
public:
    ABoilerPipe(const FObjectInitializer& ObjectInitializer);
};

