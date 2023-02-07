#pragma once
#include "CoreMinimal.h"
#include "UberExposureColorGrading.h"
#include "UberExposureColorGradingShadows.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FUberExposureColorGradingShadows : public FUberExposureColorGrading {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseShadowsMax: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ShadowsMax;
    
    DAYNIGHT_API FUberExposureColorGradingShadows();
};

