#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValue.h"
#include "ExposureExpressionsBiasedMaxExposureValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsBiasedMaxExposureValue : public UExposureExpressionsExposureValue {
    GENERATED_BODY()
public:
    UExposureExpressionsBiasedMaxExposureValue();
};

