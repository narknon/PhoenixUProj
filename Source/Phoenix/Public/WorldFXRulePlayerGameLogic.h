#pragma once
#include "CoreMinimal.h"
#include "WorldFXRule.h"
#include "WorldFXRulePlayerGameLogic.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRulePlayerGameLogic : public UWorldFXRule {
    GENERATED_BODY()
public:
    UWorldFXRulePlayerGameLogic();
};

