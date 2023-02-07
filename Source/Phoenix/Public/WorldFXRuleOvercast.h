#pragma once
#include "CoreMinimal.h"
#include "WorldFXRule.h"
#include "WorldFXRuleOvercast.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleOvercast : public UWorldFXRule {
    GENERATED_BODY()
public:
    UWorldFXRuleOvercast();
};

