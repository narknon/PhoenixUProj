#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleBlendDomainRange.h"
#include "WorldFXRuleBlendDomainPlayer.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleBlendDomainPlayer : public UWorldFXRuleBlendDomainRange {
    GENERATED_BODY()
public:
    UWorldFXRuleBlendDomainPlayer();
};

