#pragma once
#include "CoreMinimal.h"
#include "WorldFXRule.h"
#include "WorldFXRuleWeatherWindSpeed.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleWeatherWindSpeed : public UWorldFXRule {
    GENERATED_BODY()
public:
    UWorldFXRuleWeatherWindSpeed();
};

