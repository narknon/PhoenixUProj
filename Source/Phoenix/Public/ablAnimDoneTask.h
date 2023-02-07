#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EEnemyAIAnimState.h"
#include "ablAnimDoneTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablAnimDoneTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyAIAnimState State;
    
public:
    UablAnimDoneTask();
};

