#pragma once
#include "CoreMinimal.h"
#include "LightParameterSmoothingDiscontinuitySettings.generated.h"

USTRUCT(BlueprintType)
struct FLightParameterSmoothingDiscontinuitySettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDeltaRealTimeSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDeltaTimeOfDayHours;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDeltaNormalizedTimeHours;
    
    DAYNIGHT_API FLightParameterSmoothingDiscontinuitySettings();
};

