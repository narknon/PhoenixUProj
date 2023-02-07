#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValueOp.h"
#include "ExposureExpressionsScalarValueDivide.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueDivide : public UExposureExpressionsScalarValueOp {
    GENERATED_BODY()
public:
    UExposureExpressionsScalarValueDivide();
};

