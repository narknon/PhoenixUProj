#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "FXAutoTriggerBoolHasSenseGroup.generated.h"

class UAISense_CogGroup;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolHasSenseGroup : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<UAISense_CogGroup>> Senses;
    
    UFXAutoTriggerBoolHasSenseGroup();
};

