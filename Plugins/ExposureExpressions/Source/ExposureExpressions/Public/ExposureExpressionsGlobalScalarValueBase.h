#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsScalarValue.h"
#include "ExposureExpressionsGlobalScalarValueBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsGlobalScalarValueBase : public UExposureExpressionsScalarValue {
    GENERATED_BODY()
public:
    UExposureExpressionsGlobalScalarValueBase();
};

