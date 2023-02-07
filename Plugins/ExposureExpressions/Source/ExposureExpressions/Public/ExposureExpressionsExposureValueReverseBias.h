#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValueSingle.h"
#include "ExposureExpressionsExposureValueReverseBias.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureValueReverseBias : public UExposureExpressionsExposureValueSingle {
    GENERATED_BODY()
public:
    UExposureExpressionsExposureValueReverseBias();
};

