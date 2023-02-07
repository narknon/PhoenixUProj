#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeatherDecalDefinitions.generated.h"

class UWeatherDecal;

UCLASS(Blueprintable, Deprecated, NotPlaceable)
class WEATHER_API UDEPRECATED_WeatherDecalDefinitions : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWeatherDecal*> Decals;
    
    UDEPRECATED_WeatherDecalDefinitions();
};

