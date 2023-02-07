#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsValue.h"
#include "ExposureExpressionsExposureValue.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureValue : public UExposureExpressionsValue {
    GENERATED_BODY()
public:
    UExposureExpressionsExposureValue();
};

