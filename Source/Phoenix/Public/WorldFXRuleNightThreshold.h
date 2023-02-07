#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleNightDayThreshold.h"
#include "WorldFXRuleNightThreshold.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleNightThreshold : public UWorldFXRuleNightDayThreshold {
    GENERATED_BODY()
public:
    UWorldFXRuleNightThreshold();
};

