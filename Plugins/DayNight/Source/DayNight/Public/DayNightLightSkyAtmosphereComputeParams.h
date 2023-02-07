#pragma once
#include "CoreMinimal.h"
#include "DayNightLightSkyAtmosphereComputeDirectionalLightParams.h"
#include "DayNightLightSkyAtmosphereComputeSampleDirectionParams.h"
#include "DayNightLightSkyAtmosphereComputeParams.generated.h"

USTRUCT(BlueprintType)
struct FDayNightLightSkyAtmosphereComputeParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDayNightLightSkyAtmosphereComputeDirectionalLightParams SunParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDayNightLightSkyAtmosphereComputeDirectionalLightParams MoonParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDayNightLightSkyAtmosphereComputeSampleDirectionParams DirectionParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Desaturation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDesaturateWithOvercast;
    
    DAYNIGHT_API FDayNightLightSkyAtmosphereComputeParams();
};

