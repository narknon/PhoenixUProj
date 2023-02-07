#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SkinFXEventTrigger.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class SKINFX_API USkinFXEventTrigger : public UObject {
    GENERATED_BODY()
public:
    USkinFXEventTrigger();
};

