#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleNightDayThreshold.h"
#include "WorldFXRuleDayThreshold.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleDayThreshold : public UWorldFXRuleNightDayThreshold {
    GENERATED_BODY()
public:
    UWorldFXRuleDayThreshold();
};

