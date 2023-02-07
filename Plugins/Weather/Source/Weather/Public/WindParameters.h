#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "WindParametersInstant.h"
#include "WindParameters.generated.h"

USTRUCT(BlueprintType)
struct WEATHER_API FWindParameters : public FWindParametersInstant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve ModAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve ModSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLoopModAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLoopModSpeed;
    
    FWindParameters();
};

