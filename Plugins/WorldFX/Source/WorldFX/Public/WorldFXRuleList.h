#pragma once
#include "CoreMinimal.h"
#include "WorldFXRule.h"
#include "WorldFXRuleList.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleList : public UWorldFXRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWorldFXRule*> Rules;
    
    UWorldFXRuleList();
};

