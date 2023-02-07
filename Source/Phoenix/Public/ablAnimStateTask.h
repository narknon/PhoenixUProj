#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EEnemyAIAnimState.h"
#include "ablAnimStateTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablAnimStateTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyAIAnimState State;
    
public:
    UablAnimStateTask();
};

