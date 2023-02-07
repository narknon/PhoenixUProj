#pragma once
#include "CoreMinimal.h"
#include "EFXAutoTriggerConditionType.h"
#include "FXAutoTriggerConditionBase.h"
#include "FXAutoTriggerCondition.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UFXAutoTriggerCondition : public UFXAutoTriggerConditionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFXAutoTriggerConditionType Type;
    
    UFXAutoTriggerCondition();
};

