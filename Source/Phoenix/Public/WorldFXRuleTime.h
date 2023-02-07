#pragma once
#include "CoreMinimal.h"
#include "WorldFXRule.h"
#include "WorldFXRuleTime.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleTime : public UWorldFXRule {
    GENERATED_BODY()
public:
    UWorldFXRuleTime();
};

