#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightStatsSingleton.generated.h"

UCLASS(Blueprintable, NotPlaceable, Transient)
class LIGHTCULLING_API ALightStatsSingleton : public AActor {
    GENERATED_BODY()
public:
    ALightStatsSingleton(const FObjectInitializer& ObjectInitializer);
};

