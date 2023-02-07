#pragma once
#include "CoreMinimal.h"
#include "EDayNightEventDirectionTrigger.h"
#include "DayNightSunAltitudeEvent.generated.h"

USTRUCT(BlueprintType)
struct FDayNightSunAltitudeEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SunAltitudeDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDayNightEventDirectionTrigger DirectionTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowFireOnBeginPlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowFireOnDiscontinuity;
    
    DAYNIGHT_API FDayNightSunAltitudeEvent();
};

