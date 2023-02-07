#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerConditionBase.h"
#include "FXAutoTriggerConditionList.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerConditionList : public UFXAutoTriggerConditionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXAutoTriggerConditionBase*> Conditions;
    
    UFXAutoTriggerConditionList();
};

