#pragma once
#include "CoreMinimal.h"
#include "VolumetricCloudsPresetParams.h"
#include "SceneAction_WeatherSequenceCloudsPreset.h"
#include "SceneAction_WeatherSequenceCloudsParams.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceCloudsParams : public USceneAction_WeatherSequenceCloudsPreset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsPresetParams Params;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSuperExpensiveCloudsCinematicOnly;
    
    USceneAction_WeatherSequenceCloudsParams();
};

