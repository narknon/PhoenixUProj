#pragma once
#include "CoreMinimal.h"
#include "EWeatherSurfacePrecipitation.h"
#include "EWeatherSurfaceStormType.h"
#include "SceneAction_WeatherSequence.h"
#include "SceneAction_WeatherSequenceStorm.generated.h"

class UWeatherSurfaceDataAsset;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceStorm : public USceneAction_WeatherSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeatherSurfacePrecipitation PrecipitationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeatherSurfaceStormType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWeatherSurfaceDataAsset> Precipitation;
    
protected:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWeatherSurfaceDataAsset* PreloadedPrecipitation;
    
public:
    USceneAction_WeatherSequenceStorm();
};

