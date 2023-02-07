#pragma once
#include "CoreMinimal.h"
#include "SolarNormalizedTime.generated.h"

USTRUCT(BlueprintType)
struct DAYNIGHT_API FSolarNormalizedTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NormalizedTime;
    
    FSolarNormalizedTime();
};

