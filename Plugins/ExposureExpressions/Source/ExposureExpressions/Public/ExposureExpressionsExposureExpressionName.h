#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsDropdownName.h"
#include "ExposureExpressionsExposureExpressionName.generated.h"

USTRUCT(BlueprintType)
struct FExposureExpressionsExposureExpressionName : public FExposureExpressionsDropdownName {
    GENERATED_BODY()
public:
    EXPOSUREEXPRESSIONS_API FExposureExpressionsExposureExpressionName();
};

