#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendableBase.h"
#include "VolumetricCloudsPresetParameters.h"
#include "VolumetricCloudsWindParameters.h"
#include "GlobalLightingBlendableWeatherClouds.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UGlobalLightingBlendableWeatherClouds : public UGlobalLightingBlendableBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsPresetParameters PresetParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsWindParameters WindParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPresetValid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWindValid;
    
    UGlobalLightingBlendableWeatherClouds();
};

