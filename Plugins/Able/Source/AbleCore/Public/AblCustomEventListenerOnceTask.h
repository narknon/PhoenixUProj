#pragma once
#include "CoreMinimal.h"
#include "AblCustomEventListenerTask.h"
#include "AblCustomEventListenerOnceTask.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblCustomEventListenerOnceTask : public UAblCustomEventListenerTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventName;
    
    UAblCustomEventListenerOnceTask();
};

