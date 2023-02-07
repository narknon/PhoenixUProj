#pragma once
#include "CoreMinimal.h"
#include "WorldFXRule.h"
#include "WorldFXRuleSeasonBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleSeasonBase : public UWorldFXRule {
    GENERATED_BODY()
public:
    UWorldFXRuleSeasonBase();
};

