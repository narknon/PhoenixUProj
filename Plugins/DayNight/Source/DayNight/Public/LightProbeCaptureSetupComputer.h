#pragma once
#include "CoreMinimal.h"
#include "EphemerisDayInfo.h"
#include "LightProbeCaptureTimeInterval.h"
#include "LightProbeCaptureSetupComputer.generated.h"

USTRUCT(BlueprintType)
struct DAYNIGHT_API FLightProbeCaptureSetupComputer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEphemerisDayInfo DayInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLightProbeCaptureTimeInterval> CaptureTimeIntervals;
    
    FLightProbeCaptureSetupComputer();
};

