#pragma once
#include "CoreMinimal.h"
#include "Name_GameLogicVarFloat.h"
#include "WorldFXRulePlayerGameLogic.h"
#include "WorldFXRulePlayerVariableFloat.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRulePlayerVariableFloat : public UWorldFXRulePlayerGameLogic {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicVarFloat PlayerVariable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float minThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float maxThreshold;
    
    UWorldFXRulePlayerVariableFloat();
};

