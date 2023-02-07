#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtraLerp.h"
#include "ExposureExpressionsExtraLerpExposure.generated.h"

USTRUCT(BlueprintType)
struct EXPOSUREEXPRESSIONS_API FExposureExpressionsExtraLerpExposure : public FExposureExpressionsExtraLerp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CachedFactor;
    
    FExposureExpressionsExtraLerpExposure();
};

