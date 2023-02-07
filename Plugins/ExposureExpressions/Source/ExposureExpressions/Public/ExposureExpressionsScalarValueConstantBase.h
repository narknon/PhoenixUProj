#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValue.h"
#include "ExposureExpressionsScalarValueConstantBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueConstantBase : public UExposureExpressionsScalarValue {
    GENERATED_BODY()
public:
    UExposureExpressionsScalarValueConstantBase();
};

