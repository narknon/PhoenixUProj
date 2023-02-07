#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleTimeInRange.h"
#include "WorldFXRuleGameTimeInRange.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleGameTimeInRange : public UWorldFXRuleTimeInRange {
    GENERATED_BODY()
public:
    UWorldFXRuleGameTimeInRange();
};

