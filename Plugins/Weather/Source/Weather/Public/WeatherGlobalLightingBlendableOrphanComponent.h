#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendableInterface.h"
#include "WeatherOrphanComponent.h"
#include "WeatherGlobalLightingBlendableOrphanComponent.generated.h"

class UGlobalLightingBlendable;

UCLASS(Blueprintable, NonTransient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WEATHER_API UWeatherGlobalLightingBlendableOrphanComponent : public UWeatherOrphanComponent, public IGlobalLightingBlendableInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGlobalLightingBlendable* Blendable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UWeatherGlobalLightingBlendableOrphanComponent();
    
    // Fix for true pure virtual functions not being implemented
};

