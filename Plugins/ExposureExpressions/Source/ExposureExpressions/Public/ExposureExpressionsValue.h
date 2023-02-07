#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ExposureExpressionsValue.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class EXPOSUREEXPRESSIONS_API UExposureExpressionsValue : public UObject {
    GENERATED_BODY()
public:
    UExposureExpressionsValue();
};

