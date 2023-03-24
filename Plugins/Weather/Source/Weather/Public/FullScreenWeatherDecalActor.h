#pragma once
#include "CoreMinimal.h"
#include "Engine/DecalActor.h"
#include "FullScreenWeatherDecalActor.generated.h"

UCLASS(Blueprintable, NotPlaceable, Transient)
class WEATHER_API AFullScreenWeatherDecalActor : public ADecalActor {
    GENERATED_BODY()
public:
    AFullScreenWeatherDecalActor(const FObjectInitializer& ObjectInitializer);
};

