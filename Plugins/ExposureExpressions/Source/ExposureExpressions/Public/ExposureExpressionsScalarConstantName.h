#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsDropdownName.h"
#include "ExposureExpressionsScalarConstantName.generated.h"

USTRUCT(BlueprintType)
struct FExposureExpressionsScalarConstantName : public FExposureExpressionsDropdownName {
    GENERATED_BODY()
public:
    EXPOSUREEXPRESSIONS_API FExposureExpressionsScalarConstantName();
};

