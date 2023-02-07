#pragma once
#include "CoreMinimal.h"
#include "EDayNightEventDirectionTrigger.h"
#include "DayNightSunAltitudeChangeEvent.generated.h"

USTRUCT(BlueprintType)
struct FDayNightSunAltitudeChangeEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SunAltitudeChangeDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDayNightEventDirectionTrigger Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SunMinAltitudeDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SunMaxAltitudeDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowFireOnBeginPlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowFireOnDiscontinuity;
    
    DAYNIGHT_API FDayNightSunAltitudeChangeEvent();
};

