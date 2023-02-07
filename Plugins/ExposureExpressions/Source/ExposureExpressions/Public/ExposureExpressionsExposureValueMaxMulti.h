#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValueMulti.h"
#include "ExposureExpressionsExposureValueMaxMulti.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsExposureValueMaxMulti : public UExposureExpressionsExposureValueMulti {
    GENERATED_BODY()
public:
    UExposureExpressionsExposureValueMaxMulti();
};

