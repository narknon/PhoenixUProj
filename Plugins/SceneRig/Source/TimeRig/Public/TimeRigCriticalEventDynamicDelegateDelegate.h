#pragma once
#include "CoreMinimal.h"
#include "TimeRigCriticalEventDynamicDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FTimeRigCriticalEventDynamicDelegate, bool, IsCritical);

