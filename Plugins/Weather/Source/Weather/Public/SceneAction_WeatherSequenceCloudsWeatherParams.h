#pragma once
#include "CoreMinimal.h"
#include "VolumetricCloudsWeatherState.h"
#include "SceneAction_WeatherSequenceCloudsPreset.h"
#include "SceneAction_WeatherSequenceCloudsWeatherParams.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceCloudsWeatherParams : public USceneAction_WeatherSequenceCloudsPreset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsWeatherState WeatherState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightOffset;
    
    USceneAction_WeatherSequenceCloudsWeatherParams();
};

