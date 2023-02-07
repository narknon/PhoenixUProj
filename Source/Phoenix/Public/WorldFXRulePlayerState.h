#pragma once
#include "CoreMinimal.h"
#include "WorldFXRule.h"
#include "WorldFXRulePlayerState.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRulePlayerState : public UWorldFXRule {
    GENERATED_BODY()
public:
    UWorldFXRulePlayerState();
};

