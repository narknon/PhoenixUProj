#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerPrerequisiteBase.h"
#include "FXAutoTriggerPrerequisiteAnd.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerPrerequisiteAnd : public UFXAutoTriggerPrerequisiteBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXAutoTriggerPrerequisiteBase*> Conditions;
    
    UFXAutoTriggerPrerequisiteAnd();
};

