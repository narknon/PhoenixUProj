#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "VolumetricCloudsDetailParams.h"
#include "VolumetricCloudsHighAltitudeParams.h"
#include "VolumetricCloudsWeatherCoverageParams.h"
#include "VolumetricCloudsWeatherPrecipitationParams.h"
#include "VolumetricCloudsWeatherTypeParams.h"
#include "VolumetricCloudsPresetParams.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct VOLUMETRICCLOUDS_API FVolumetricCloudsPresetParams : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsWeatherCoverageParams WeatherCoverage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsWeatherTypeParams WeatherType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsWeatherPrecipitationParams WeatherPrecipitation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsHighAltitudeParams HighAltitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsDetailParams Detail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    UTexture2D* OverrideWeather;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    UTexture2D* OverrideTypeLut;
    
    FVolumetricCloudsPresetParams();
};

