#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValuePair.h"
#include "ExposureExpressionsExposureValueFunction.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureValueFunction : public UExposureExpressionsExposureValuePair {
    GENERATED_BODY()
public:
    UExposureExpressionsExposureValueFunction();
};

