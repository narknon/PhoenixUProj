#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "Name_GameLogicBoolResult.h"
#include "FXAutoTriggerBoolGameLogicResultOnOff.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolGameLogicResultOnOff : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicBoolResult Result;
    
    UFXAutoTriggerBoolGameLogicResultOnOff();
};

