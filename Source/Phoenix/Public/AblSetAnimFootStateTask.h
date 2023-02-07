#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EBasicMobilityFootState.h"
#include "AblSetAnimFootStateTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblSetAnimFootStateTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBasicMobilityFootState FootState;
    
public:
    UAblSetAnimFootStateTask();
};

