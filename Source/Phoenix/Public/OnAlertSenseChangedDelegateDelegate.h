#pragma once
#include "CoreMinimal.h"
#include "OnAlertSenseChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAlertSenseChangedDelegate, float, SenseValue);

