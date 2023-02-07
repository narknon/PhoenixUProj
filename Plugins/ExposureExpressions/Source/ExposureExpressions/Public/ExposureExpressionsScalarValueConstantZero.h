#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValueConstantBase.h"
#include "ExposureExpressionsScalarValueConstantZero.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueConstantZero : public UExposureExpressionsScalarValueConstantBase {
    GENERATED_BODY()
public:
    UExposureExpressionsScalarValueConstantZero();
};

