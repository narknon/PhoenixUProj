#pragma once
#include "CoreMinimal.h"
#include "Interfaces/Interface_PostProcessVolume.h"
#include "Engine/Scene.h"
#include "WeatherOrphanComponent.h"
#include "WeatherPostProcessingOrphanComponent.generated.h"

UCLASS(Blueprintable, NonTransient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WEATHER_API UWeatherPostProcessingOrphanComponent : public UWeatherOrphanComponent/*, public IInterface_PostProcessVolume*/ {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FPostProcessSettings PostProcessSettings;
    
    UWeatherPostProcessingOrphanComponent();
    
    // Fix for true pure virtual functions not being implemented
};

