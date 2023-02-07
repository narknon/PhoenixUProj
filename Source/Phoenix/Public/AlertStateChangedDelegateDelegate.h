#pragma once
#include "CoreMinimal.h"
#include "ENPC_TargetAwareState.h"
#include "AlertStateChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAlertStateChangedDelegate, ENPC_TargetAwareState, AlertState);

