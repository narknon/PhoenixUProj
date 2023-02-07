#pragma once
#include "CoreMinimal.h"
#include "TimeInput.h"
#include "LightProbeCaptureTimeInput.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FLightProbeCaptureTimeInput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeInput Time;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* LerpCurve;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFlipLerpCurveT;
    
    DAYNIGHT_API FLightProbeCaptureTimeInput();
};

