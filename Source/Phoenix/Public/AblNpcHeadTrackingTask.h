#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "AblNpcHeadTrackingTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblNpcHeadTrackingTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableHeadTracking;
    
public:
    UAblNpcHeadTrackingTask();
};

