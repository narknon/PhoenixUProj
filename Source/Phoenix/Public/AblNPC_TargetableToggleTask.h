#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblNPC_TargetableToggleTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNPC_TargetableToggleTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRegisterAsTargetableAtStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRegisterAsTargetableAtEnd;
    
public:
    UAblNPC_TargetableToggleTask();
};

