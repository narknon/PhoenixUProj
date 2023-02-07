#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValueFunction.h"
#include "ExposureExpressionsExposureValueMedian.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureValueMedian : public UExposureExpressionsExposureValueFunction {
    GENERATED_BODY()
public:
    UExposureExpressionsExposureValueMedian();
};

