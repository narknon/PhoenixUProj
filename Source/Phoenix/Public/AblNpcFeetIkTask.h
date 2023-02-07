#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EAblNpcReactEventAction.h"
#include "AblNpcFeetIkTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNpcFeetIkTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAblNpcReactEventAction IkOnTaskStartEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAblNpcReactEventAction IkOnTaskEndEvent;
    
public:
    UAblNpcFeetIkTask();
};

