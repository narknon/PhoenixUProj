#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FXAutoTriggerRequiredActorsMatchBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class FXUTIL_API UFXAutoTriggerRequiredActorsMatchBase : public UObject {
    GENERATED_BODY()
public:
    UFXAutoTriggerRequiredActorsMatchBase();
};

