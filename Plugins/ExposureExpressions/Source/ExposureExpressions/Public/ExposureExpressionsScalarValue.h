#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsValue.h"
#include "ExposureExpressionsScalarValue.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValue : public UExposureExpressionsValue {
    GENERATED_BODY()
public:
    UExposureExpressionsScalarValue();
};

