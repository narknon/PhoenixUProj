#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FXAutoTriggerRequiredActorsBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class FXUTIL_API UFXAutoTriggerRequiredActorsBase : public UObject {
    GENERATED_BODY()
public:
    UFXAutoTriggerRequiredActorsBase();
};

