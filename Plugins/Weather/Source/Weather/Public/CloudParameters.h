#pragma once
#include "CoreMinimal.h"
#include "VolumetricCloudsPresetParams.h"
#include "VolumetricCloudsWeatherWindParams.h"
#include "SunDiskOverrides.h"
#include "CloudParameters.generated.h"

USTRUCT(BlueprintType)
struct FCloudParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsPresetParams Params;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVolumetricCloudsWeatherWindParams WindParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSunDiskOverrides SunDiskOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Overcast;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSuperExpensiveCloudsCinematicOnly;
    
    WEATHER_API FCloudParameters();
};

