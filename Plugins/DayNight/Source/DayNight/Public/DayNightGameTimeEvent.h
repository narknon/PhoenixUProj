#pragma once
#include "CoreMinimal.h"
#include "TimeInput.h"
#include "DayNightGameTimeEvent.generated.h"

USTRUCT(BlueprintType)
struct FDayNightGameTimeEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeInput GameTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowFireOnBeginPlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowFireOnDiscontinuity;
    
    DAYNIGHT_API FDayNightGameTimeEvent();
};

