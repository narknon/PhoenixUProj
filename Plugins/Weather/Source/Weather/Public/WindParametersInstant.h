#pragma once
#include "CoreMinimal.h"
#include "WindParametersInstant.generated.h"

USTRUCT(BlueprintType)
struct WEATHER_API FWindParametersInstant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Angle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedMS;
    
    FWindParametersInstant();
};

