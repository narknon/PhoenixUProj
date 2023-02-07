#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerRequiredActorsMatchBase.h"
#include "FXAutoTriggerRequiredActorsMatchNot.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerRequiredActorsMatchNot : public UFXAutoTriggerRequiredActorsMatchBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerRequiredActorsMatchBase* Condition;
    
    UFXAutoTriggerRequiredActorsMatchNot();
};

