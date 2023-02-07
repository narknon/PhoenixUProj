#pragma once
#include "CoreMinimal.h"
#include "EDayNightEventDirection.h"
#include "DayNightEventsCurrentAltitude.generated.h"

USTRUCT(BlueprintType)
struct FDayNightEventsCurrentAltitude {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Altitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDayNightEventDirection Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bValid;
    
    DAYNIGHT_API FDayNightEventsCurrentAltitude();
};

