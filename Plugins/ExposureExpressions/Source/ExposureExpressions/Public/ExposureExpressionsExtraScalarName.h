#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsDropdownName.h"
#include "ExposureExpressionsExtraScalarName.generated.h"

USTRUCT(BlueprintType)
struct FExposureExpressionsExtraScalarName : public FExposureExpressionsDropdownName {
    GENERATED_BODY()
public:
    EXPOSUREEXPRESSIONS_API FExposureExpressionsExtraScalarName();
};

