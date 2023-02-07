#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FXAutoTriggerConditionBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class FXUTIL_API UFXAutoTriggerConditionBase : public UObject {
    GENERATED_BODY()
public:
    UFXAutoTriggerConditionBase();
};

