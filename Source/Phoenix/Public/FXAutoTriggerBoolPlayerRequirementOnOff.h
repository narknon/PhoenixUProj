#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "Name_GameLogicVarBool.h"
#include "FXAutoTriggerBoolPlayerRequirementOnOff.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolPlayerRequirementOnOff : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicVarBool PlayerRequirement;
    
    UFXAutoTriggerBoolPlayerRequirementOnOff();
};

