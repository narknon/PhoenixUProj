#pragma once
#include "CoreMinimal.h"
#include "AblCustomEventListenerTask.h"
#include "AblCustomEventListenerStartEndTask.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblCustomEventListenerStartEndTask : public UAblCustomEventListenerTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StartEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EndEventName;
    
    UAblCustomEventListenerStartEndTask();
};

