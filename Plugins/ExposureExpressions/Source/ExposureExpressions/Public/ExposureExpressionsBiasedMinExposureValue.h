#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValue.h"
#include "ExposureExpressionsBiasedMinExposureValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsBiasedMinExposureValue : public UExposureExpressionsExposureValue {
    GENERATED_BODY()
public:
    UExposureExpressionsBiasedMinExposureValue();
};

