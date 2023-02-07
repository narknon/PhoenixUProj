#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "ablExecuteTask.generated.h"

class UExecuteTask;

UCLASS(Blueprintable, EditInlineNew)
class UablExecuteTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExecuteTask* ExecuteTask;
    
public:
    UablExecuteTask();
};

