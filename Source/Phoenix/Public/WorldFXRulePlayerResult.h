#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicBoolResult.h"
#include "WorldFXRulePlayerGameLogic.h"
#include "WorldFXRulePlayerResult.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRulePlayerResult : public UWorldFXRulePlayerGameLogic {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicBoolResult PlayerResult;
    
    UWorldFXRulePlayerResult();
};

