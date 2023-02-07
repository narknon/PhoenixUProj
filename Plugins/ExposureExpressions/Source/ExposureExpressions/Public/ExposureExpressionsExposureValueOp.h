#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValuePair.h"
#include "ExposureExpressionsExposureValueOp.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureValueOp : public UExposureExpressionsExposureValuePair {
    GENERATED_BODY()
public:
    UExposureExpressionsExposureValueOp();
};

