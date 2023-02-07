#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FXAutoTriggerValue.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class FXUTIL_API UFXAutoTriggerValue : public UObject {
    GENERATED_BODY()
public:
    UFXAutoTriggerValue();
};

