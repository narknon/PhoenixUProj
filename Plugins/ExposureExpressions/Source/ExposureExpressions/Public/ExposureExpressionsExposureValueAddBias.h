#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValueSingle.h"
#include "ExposureExpressionsExposureValueAddBias.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureValueAddBias : public UExposureExpressionsExposureValueSingle {
    GENERATED_BODY()
public:
    UExposureExpressionsExposureValueAddBias();
};

