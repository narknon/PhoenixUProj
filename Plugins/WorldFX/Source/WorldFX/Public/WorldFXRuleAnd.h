#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleList.h"
#include "WorldFXRuleAnd.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleAnd : public UWorldFXRuleList {
    GENERATED_BODY()
public:
    UWorldFXRuleAnd();
};

