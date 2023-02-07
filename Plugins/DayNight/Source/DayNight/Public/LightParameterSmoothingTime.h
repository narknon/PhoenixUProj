#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LightParameterSmoothingTime.generated.h"

USTRUCT(BlueprintType)
struct FLightParameterSmoothingTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RealTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime TimeOfDay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NormalizedTime;
    
    DAYNIGHT_API FLightParameterSmoothingTime();
};

