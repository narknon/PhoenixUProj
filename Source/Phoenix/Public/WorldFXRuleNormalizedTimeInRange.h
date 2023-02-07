#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleTimeInRange.h"
#include "WorldFXRuleNormalizedTimeInRange.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleNormalizedTimeInRange : public UWorldFXRuleTimeInRange {
    GENERATED_BODY()
public:
    UWorldFXRuleNormalizedTimeInRange();
};

