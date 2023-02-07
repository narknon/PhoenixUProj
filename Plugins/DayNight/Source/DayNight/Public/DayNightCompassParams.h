#pragma once
#include "CoreMinimal.h"
#include "DayNightCompassParams.generated.h"

USTRUCT(BlueprintType)
struct FDayNightCompassParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RadiusMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Scale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WorldAzimuthOffsetDegrees;
    
    DAYNIGHT_API FDayNightCompassParams();
};

