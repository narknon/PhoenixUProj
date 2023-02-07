#pragma once
#include "CoreMinimal.h"
#include "WatchedConsoleVariableDynamicDelegateIntDelegate.generated.h"

class UWatchedConsoleVariableInt;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWatchedConsoleVariableDynamicDelegateInt, UWatchedConsoleVariableInt*, Variable);

