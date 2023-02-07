#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtraLerp.h"
#include "ExposureExpressionsExtraLerpScalar.generated.h"

USTRUCT(BlueprintType)
struct EXPOSUREEXPRESSIONS_API FExposureExpressionsExtraLerpScalar : public FExposureExpressionsExtraLerp {
    GENERATED_BODY()
public:
    FExposureExpressionsExtraLerpScalar();
};

