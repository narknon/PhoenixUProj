#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "Name_GameLogicBoolResult.h"
#include "FXAutoTriggerBoolPlayerResult.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolPlayerResult : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicBoolResult PlayerResult;
    
    UFXAutoTriggerBoolPlayerResult();
};

