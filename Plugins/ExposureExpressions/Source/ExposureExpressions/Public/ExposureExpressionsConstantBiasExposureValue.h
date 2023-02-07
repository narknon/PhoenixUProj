#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValue.h"
#include "ExposureExpressionsConstantBiasExposureValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsConstantBiasExposureValue : public UExposureExpressionsExposureValue {
    GENERATED_BODY()
public:
    UExposureExpressionsConstantBiasExposureValue();
};

