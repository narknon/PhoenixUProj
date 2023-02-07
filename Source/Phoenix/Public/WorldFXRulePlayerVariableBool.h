#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicVarBool.h"
#include "WorldFXRulePlayerGameLogic.h"
#include "WorldFXRulePlayerVariableBool.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRulePlayerVariableBool : public UWorldFXRulePlayerGameLogic {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicVarBool PlayerVariable;
    
    UWorldFXRulePlayerVariableBool();
};

