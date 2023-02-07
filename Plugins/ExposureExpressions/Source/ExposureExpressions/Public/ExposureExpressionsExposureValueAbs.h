#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValueSingle.h"
#include "ExposureExpressionsExposureValueAbs.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureValueAbs : public UExposureExpressionsExposureValueSingle {
    GENERATED_BODY()
public:
    UExposureExpressionsExposureValueAbs();
};

