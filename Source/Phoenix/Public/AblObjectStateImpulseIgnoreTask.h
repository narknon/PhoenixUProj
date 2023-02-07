#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblObjectStateImpulseIgnoreTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblObjectStateImpulseIgnoreTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseTaskDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpulseIgnoreDuration;
    
    UAblObjectStateImpulseIgnoreTask();
};

