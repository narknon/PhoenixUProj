#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicExpression.h"
#include "WorldFXRulePlayerGameLogic.h"
#include "WorldFXRulePlayerExpression.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRulePlayerExpression : public UWorldFXRulePlayerGameLogic {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicExpression PlayerExpression;
    
    UWorldFXRulePlayerExpression();
};

