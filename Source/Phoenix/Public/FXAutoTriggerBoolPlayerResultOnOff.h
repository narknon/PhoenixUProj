#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "Name_GameLogicBoolResult.h"
#include "FXAutoTriggerBoolPlayerResultOnOff.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolPlayerResultOnOff : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicBoolResult PlayerResult;
    
    UFXAutoTriggerBoolPlayerResultOnOff();
};

