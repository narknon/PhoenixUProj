#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValueFunction.h"
#include "ExposureExpressionsScalarValueStep.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueStep : public UExposureExpressionsScalarValueFunction {
    GENERATED_BODY()
public:
    UExposureExpressionsScalarValueStep();
};

