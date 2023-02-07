#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogVolumetricNoiseParametersOverride.h"
#include "SceneAction_WeatherSequenceFogNoise.h"
#include "SceneAction_WeatherSequenceFogNoiseOverride.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceFogNoiseOverride : public USceneAction_WeatherSequenceFogNoise {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricNoiseParametersOverride Noise;
    
    USceneAction_WeatherSequenceFogNoiseOverride();
};

