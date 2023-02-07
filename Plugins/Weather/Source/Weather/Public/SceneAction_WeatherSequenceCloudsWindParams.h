#pragma once
#include "CoreMinimal.h"
#include "VolumetricCloudsWeatherWindParams.h"
#include "SceneAction_WeatherSequenceCloudsWind.h"
#include "SceneAction_WeatherSequenceCloudsWindParams.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceCloudsWindParams : public USceneAction_WeatherSequenceCloudsWind {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsWeatherWindParams WindParams;
    
    USceneAction_WeatherSequenceCloudsWindParams();
};

