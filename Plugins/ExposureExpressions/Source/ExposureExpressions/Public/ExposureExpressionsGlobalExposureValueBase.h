#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExposureValue.h"
#include "ExposureExpressionsGlobalExposureValueBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsGlobalExposureValueBase : public UExposureExpressionsExposureValue {
    GENERATED_BODY()
public:
    UExposureExpressionsGlobalExposureValueBase();
};

