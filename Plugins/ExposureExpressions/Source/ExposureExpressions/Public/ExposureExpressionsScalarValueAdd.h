#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValueOp.h"
#include "ExposureExpressionsScalarValueAdd.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueAdd : public UExposureExpressionsScalarValueOp {
    GENERATED_BODY()
public:
    UExposureExpressionsScalarValueAdd();
};

