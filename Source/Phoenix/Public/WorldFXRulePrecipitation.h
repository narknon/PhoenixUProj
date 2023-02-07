#pragma once
#include "CoreMinimal.h"
#include "WorldFXRule.h"
#include "WorldFXRulePrecipitation.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRulePrecipitation : public UWorldFXRule {
    GENERATED_BODY()
public:
    UWorldFXRulePrecipitation();
};

