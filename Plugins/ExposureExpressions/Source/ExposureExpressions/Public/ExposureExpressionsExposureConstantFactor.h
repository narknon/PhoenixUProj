#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValueFactor.h"
#include "ExposureExpressionsExposureConstantFactor.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureConstantFactor : public UExposureExpressionsExposureValueFactor {
    GENERATED_BODY()
public:
    UExposureExpressionsExposureConstantFactor();
};

