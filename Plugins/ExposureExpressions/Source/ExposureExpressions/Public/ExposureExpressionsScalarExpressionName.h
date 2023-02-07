#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsDropdownName.h"
#include "ExposureExpressionsScalarExpressionName.generated.h"

USTRUCT(BlueprintType)
struct FExposureExpressionsScalarExpressionName : public FExposureExpressionsDropdownName {
    GENERATED_BODY()
public:
    EXPOSUREEXPRESSIONS_API FExposureExpressionsScalarExpressionName();
};

