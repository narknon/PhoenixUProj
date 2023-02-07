#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsDropdownName.h"
#include "ExposureExpressionsExposureConstantName.generated.h"

USTRUCT(BlueprintType)
struct FExposureExpressionsExposureConstantName : public FExposureExpressionsDropdownName {
    GENERATED_BODY()
public:
    EXPOSUREEXPRESSIONS_API FExposureExpressionsExposureConstantName();
};

