#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValueSingle.h"
#include "ExposureExpressionsScalarValueNegate.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueNegate : public UExposureExpressionsScalarValueSingle {
    GENERATED_BODY()
public:
    UExposureExpressionsScalarValueNegate();
};

