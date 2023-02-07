#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleList.h"
#include "WorldFXRuleOr.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleOr : public UWorldFXRuleList {
    GENERATED_BODY()
public:
    UWorldFXRuleOr();
};

