#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerValue.h"
#include "FXAutoTriggerBool.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UFXAutoTriggerBool : public UFXAutoTriggerValue {
    GENERATED_BODY()
public:
    UFXAutoTriggerBool();
};

