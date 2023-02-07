#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValueOp.h"
#include "ExposureExpressionsScalarValueSubtract.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsScalarValueSubtract : public UExposureExpressionsScalarValueOp {
    GENERATED_BODY()
public:
    UExposureExpressionsScalarValueSubtract();
};

