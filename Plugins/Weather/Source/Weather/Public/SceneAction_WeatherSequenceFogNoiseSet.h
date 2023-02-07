#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogVolumetricNoiseParameters.h"
#include "SceneAction_WeatherSequenceFogNoise.h"
#include "SceneAction_WeatherSequenceFogNoiseSet.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceFogNoiseSet : public USceneAction_WeatherSequenceFogNoise {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricNoiseParameters Noise;
    
    USceneAction_WeatherSequenceFogNoiseSet();
};

