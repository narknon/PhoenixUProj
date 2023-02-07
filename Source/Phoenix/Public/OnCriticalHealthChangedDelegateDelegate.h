#pragma once
#include "CoreMinimal.h"
#include "OnCriticalHealthChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCriticalHealthChangedDelegate, bool, bCritical);

