#pragma once
#include "CoreMinimal.h"
#include "WorldFXRule.h"
#include "WorldFXRuleBlendDomainBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleBlendDomainBase : public UWorldFXRule {
    GENERATED_BODY()
public:
    UWorldFXRuleBlendDomainBase();
};

