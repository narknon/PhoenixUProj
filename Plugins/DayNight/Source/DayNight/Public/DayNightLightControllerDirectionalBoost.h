#pragma once
#include "CoreMinimal.h"
#include "DayNightLightControllerDirectionalBoost.generated.h"

USTRUCT(BlueprintType)
struct FDayNightLightControllerDirectionalBoost {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LightHalfAngleMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LightHalfAngleMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BoostPercentage;
    
    DAYNIGHT_API FDayNightLightControllerDirectionalBoost();
};

