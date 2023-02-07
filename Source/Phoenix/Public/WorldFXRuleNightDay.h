#pragma once
#include "CoreMinimal.h"
#include "WorldFXRule.h"
#include "WorldFXRuleNightDay.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleNightDay : public UWorldFXRule {
    GENERATED_BODY()
public:
    UWorldFXRuleNightDay();
};

