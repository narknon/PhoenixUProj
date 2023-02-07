#pragma once
#include "CoreMinimal.h"
#include "WorldFXRule.h"
#include "WorldFXRuleNot.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleNot : public UWorldFXRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWorldFXRule* Rule;
    
    UWorldFXRuleNot();
};

