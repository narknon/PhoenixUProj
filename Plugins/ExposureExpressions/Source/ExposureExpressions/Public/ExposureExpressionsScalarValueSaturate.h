#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValueSingle.h"
#include "ExposureExpressionsScalarValueSaturate.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueSaturate : public UExposureExpressionsScalarValueSingle {
    GENERATED_BODY()
public:
    UExposureExpressionsScalarValueSaturate();
};

