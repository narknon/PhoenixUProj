#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValue.h"
#include "ExposureExpressionsExposureConstant.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureConstant : public UExposureExpressionsExposureValue {
    GENERATED_BODY()
public:
    UExposureExpressionsExposureConstant();
};

