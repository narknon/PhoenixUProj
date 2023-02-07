#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerValue.h"
#include "FXAutoTriggerScalar.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UFXAutoTriggerScalar : public UFXAutoTriggerValue {
    GENERATED_BODY()
public:
    UFXAutoTriggerScalar();
};

