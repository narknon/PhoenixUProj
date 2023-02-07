#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtraLerpExposure.h"
#include "ExposureExpressionsExtraLerpScalar.h"
#include "ExposureExpressionsExtrasLerp.generated.h"

USTRUCT(BlueprintType)
struct EXPOSUREEXPRESSIONS_API FExposureExpressionsExtrasLerp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExposureExpressionsExtraLerpExposure> ExposureExtras;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExposureExpressionsExtraLerpScalar> ScalarExtras;
    
    FExposureExpressionsExtrasLerp();
};

