#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "Name_GameLogicPropInt32.h"
#include "FXAutoTriggerBoolGameLogicPropositionalInt32.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolGameLogicPropositionalInt32 : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicPropInt32 Propositional;
    
    UFXAutoTriggerBoolGameLogicPropositionalInt32();
};

