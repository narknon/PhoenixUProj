#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "Name_GameLogicVarBool.h"
#include "FXAutoTriggerScalarGameLogicRequirementOnOff.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarGameLogicRequirementOnOff : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicVarBool Requirement;
    
    UFXAutoTriggerScalarGameLogicRequirementOnOff();
};

