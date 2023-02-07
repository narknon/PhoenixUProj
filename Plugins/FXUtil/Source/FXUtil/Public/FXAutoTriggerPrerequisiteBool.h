#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerPrerequisiteBase.h"
#include "FXAutoTriggerPrerequisiteBool.generated.h"

class UFXAutoTriggerBool;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerPrerequisiteBool : public UFXAutoTriggerPrerequisiteBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerBool* Condition;
    
    UFXAutoTriggerPrerequisiteBool();
};

