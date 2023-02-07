#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblNPC_ParryLeadInPreLoopingTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNPC_ParryLeadInPreLoopingTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bParryWindowPersistPastImpact;
    
    UAblNPC_ParryLeadInPreLoopingTask();
};

