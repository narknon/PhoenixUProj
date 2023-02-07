#pragma once
#include "CoreMinimal.h"
#include "ENPC_TargetAwareState.h"
#include "TargetAwareStateChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTargetAwareStateChangedDelegate, ENPC_TargetAwareState, AlertState);

