#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "Name_GameLogicExpression.h"
#include "FXAutoTriggerBoolPlayerExpression.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolPlayerExpression : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicExpression PlayerExpression;
    
    UFXAutoTriggerBoolPlayerExpression();
};

