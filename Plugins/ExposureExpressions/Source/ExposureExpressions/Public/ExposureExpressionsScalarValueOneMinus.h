#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValueSingle.h"
#include "ExposureExpressionsScalarValueOneMinus.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueOneMinus : public UExposureExpressionsScalarValueSingle {
    GENERATED_BODY()
public:
    UExposureExpressionsScalarValueOneMinus();
};

