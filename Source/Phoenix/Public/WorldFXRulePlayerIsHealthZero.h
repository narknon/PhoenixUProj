#pragma once
#include "CoreMinimal.h"
#include "WorldFXRulePlayerState.h"
#include "WorldFXRulePlayerIsHealthZero.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRulePlayerIsHealthZero : public UWorldFXRulePlayerState {
    GENERATED_BODY()
public:
    UWorldFXRulePlayerIsHealthZero();
};

