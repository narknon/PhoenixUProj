#pragma once
#include "CoreMinimal.h"
#include "PerformTriggerTaskCompleteBPDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPerformTriggerTaskCompleteBP, const int32, CurrentTaskIndex);

