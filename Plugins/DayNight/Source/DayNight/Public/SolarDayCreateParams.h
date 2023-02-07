#pragma once
#include "CoreMinimal.h"
#include "SolarDayCreateParams.generated.h"

USTRUCT(BlueprintType)
struct FSolarDayCreateParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Samples;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ErrorThreshold;
    
    DAYNIGHT_API FSolarDayCreateParams();
};

