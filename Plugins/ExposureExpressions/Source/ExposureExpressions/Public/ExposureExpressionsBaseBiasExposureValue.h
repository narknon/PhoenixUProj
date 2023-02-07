#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValue.h"
#include "ExposureExpressionsBaseBiasExposureValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsBaseBiasExposureValue : public UExposureExpressionsExposureValue {
    GENERATED_BODY()
public:
    UExposureExpressionsBaseBiasExposureValue();
};

