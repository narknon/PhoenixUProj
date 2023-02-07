#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsDropdownName.h"
#include "ExposureExpressionsExtraExposureName.generated.h"

USTRUCT(BlueprintType)
struct FExposureExpressionsExtraExposureName : public FExposureExpressionsDropdownName {
    GENERATED_BODY()
public:
    EXPOSUREEXPRESSIONS_API FExposureExpressionsExtraExposureName();
};

