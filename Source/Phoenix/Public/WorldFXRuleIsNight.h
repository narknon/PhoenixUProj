#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleNightDay.h"
#include "WorldFXRuleIsNight.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleIsNight : public UWorldFXRuleNightDay {
    GENERATED_BODY()
public:
    UWorldFXRuleIsNight();
};

