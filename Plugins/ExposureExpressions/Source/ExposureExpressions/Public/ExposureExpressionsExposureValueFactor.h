#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValue.h"
#include "ExposureExpressionsExposureValueFactor.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureValueFactor : public UExposureExpressionsExposureValue {
    GENERATED_BODY()
public:
    UExposureExpressionsExposureValueFactor();
};

