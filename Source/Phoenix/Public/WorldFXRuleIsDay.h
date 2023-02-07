#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleNightDay.h"
#include "WorldFXRuleIsDay.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleIsDay : public UWorldFXRuleNightDay {
    GENERATED_BODY()
public:
    UWorldFXRuleIsDay();
};

