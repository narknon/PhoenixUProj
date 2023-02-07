#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblNpcHitPauseTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNpcHitPauseTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Time;
    
public:
    UAblNpcHitPauseTask();
};

