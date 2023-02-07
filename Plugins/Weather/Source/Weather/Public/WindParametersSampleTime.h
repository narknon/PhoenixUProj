#pragma once
#include "CoreMinimal.h"
#include "EWindParametersTimeBase.h"
#include "WindParametersSampleTime.generated.h"

USTRUCT(BlueprintType)
struct WEATHER_API FWindParametersSampleTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWindParametersTimeBase Base;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Factor;
    
    FWindParametersSampleTime();
};

