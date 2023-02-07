#pragma once
#include "CoreMinimal.h"
#include "LightParameterSmoothingDeltaTime.generated.h"

USTRUCT(BlueprintType)
struct FLightParameterSmoothingDeltaTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeltaRealTimeSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeltaTimeOfDayHours;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeltaNormalizedTimeHours;
    
    DAYNIGHT_API FLightParameterSmoothingDeltaTime();
};

