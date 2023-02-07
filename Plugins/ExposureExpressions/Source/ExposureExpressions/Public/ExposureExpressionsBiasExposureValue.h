#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValue.h"
#include "ExposureExpressionsBiasExposureValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsBiasExposureValue : public UExposureExpressionsExposureValue {
    GENERATED_BODY()
public:
    UExposureExpressionsBiasExposureValue();
};

