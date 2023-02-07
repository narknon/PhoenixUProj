#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValuePair.h"
#include "ExposureExpressionsScalarValueFunction.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueFunction : public UExposureExpressionsScalarValuePair {
    GENERATED_BODY()
public:
    UExposureExpressionsScalarValueFunction();
};

