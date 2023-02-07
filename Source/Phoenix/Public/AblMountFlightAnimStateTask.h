#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTask.h"
#include "EMountFlyingGait.h"
#include "AblMountFlightAnimStateTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblMountFlightAnimStateTask : public UAblAbilityTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMountFlyingGait MountFlyingGait;
    
    UAblMountFlightAnimStateTask();
};

