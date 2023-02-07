#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "Name_GameLogicExpression.h"
#include "FXAutoTriggerBoolActorExpression.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolActorExpression : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName_GameLogicExpression ActorExpression;
    
    UFXAutoTriggerBoolActorExpression();
};

