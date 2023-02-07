#pragma once
#include "CoreMinimal.h"
#include "TimeInput.h"
#include "DayNightNormalizedTimeEvent.generated.h"

USTRUCT(BlueprintType)
struct FDayNightNormalizedTimeEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeInput NormalizedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowFireOnBeginPlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowFireOnDiscontinuity;
    
    DAYNIGHT_API FDayNightNormalizedTimeEvent();
};

