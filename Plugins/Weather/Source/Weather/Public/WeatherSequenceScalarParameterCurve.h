#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "WeatherSequenceScalarParameterCurve.generated.h"

USTRUCT(BlueprintType)
struct WEATHER_API FWeatherSequenceScalarParameterCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Parameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStretchToDuration;
    
    FWeatherSequenceScalarParameterCurve();
};

