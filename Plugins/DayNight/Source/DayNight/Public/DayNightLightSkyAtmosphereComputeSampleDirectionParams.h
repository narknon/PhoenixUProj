#pragma once
#include "CoreMinimal.h"
#include "DayNightLightSkyAtmosphereComputeSampleDirectionParams.generated.h"

USTRUCT(BlueprintType)
struct FDayNightLightSkyAtmosphereComputeSampleDirectionParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SampleOffsetAltitudeDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumSampleAltitudeDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumSampleAltitudeDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMirrorLowerHemisphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseMinimumSampleAltitudeDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseMaximumSampleAltitudeDegrees;
    
    DAYNIGHT_API FDayNightLightSkyAtmosphereComputeSampleDirectionParams();
};

