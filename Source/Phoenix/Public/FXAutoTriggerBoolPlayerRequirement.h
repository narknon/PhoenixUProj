#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "Name_GameLogicVarBool.h"
#include "FXAutoTriggerBoolPlayerRequirement.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolPlayerRequirement : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicVarBool PlayerRequirement;
    
    UFXAutoTriggerBoolPlayerRequirement();
};

