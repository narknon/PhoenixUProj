#pragma once
#include "CoreMinimal.h"
#include "AIPerformTaskBase.h"
#include "AIPerformTaskEnableTriggerOverlapForPT.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskEnableTriggerOverlapForPT : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* PerformTaskTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldActivate;
    
    UAIPerformTaskEnableTriggerOverlapForPT();
};

