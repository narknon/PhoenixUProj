#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValuePair.h"
#include "ExposureExpressionsScalarValueOp.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueOp : public UExposureExpressionsScalarValuePair {
    GENERATED_BODY()
public:
    UExposureExpressionsScalarValueOp();
};

