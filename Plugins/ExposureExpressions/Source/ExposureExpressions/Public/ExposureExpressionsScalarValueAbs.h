#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValueSingle.h"
#include "ExposureExpressionsScalarValueAbs.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueAbs : public UExposureExpressionsScalarValueSingle {
    GENERATED_BODY()
public:
    UExposureExpressionsScalarValueAbs();
};

