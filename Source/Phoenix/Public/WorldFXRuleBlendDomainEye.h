#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleBlendDomainRange.h"
#include "WorldFXRuleBlendDomainEye.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleBlendDomainEye : public UWorldFXRuleBlendDomainRange {
    GENERATED_BODY()
public:
    UWorldFXRuleBlendDomainEye();
};

