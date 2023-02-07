#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "Name_GameLogicPropFloat.h"
#include "FXAutoTriggerBoolGameLogicPropositional.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolGameLogicPropositional : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicPropFloat Propositional;
    
    UFXAutoTriggerBoolGameLogicPropositional();
};

