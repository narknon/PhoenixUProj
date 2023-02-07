#pragma once
#include "CoreMinimal.h"
#include "WorldFXRulePlayerState.h"
#include "WorldFXRulePlayerIsHealthCritical.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRulePlayerIsHealthCritical : public UWorldFXRulePlayerState {
    GENERATED_BODY()
public:
    UWorldFXRulePlayerIsHealthCritical();
};

