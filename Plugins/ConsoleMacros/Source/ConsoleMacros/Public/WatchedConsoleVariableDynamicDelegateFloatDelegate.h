#pragma once
#include "CoreMinimal.h"
#include "WatchedConsoleVariableDynamicDelegateFloatDelegate.generated.h"

class UWatchedConsoleVariableFloat;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWatchedConsoleVariableDynamicDelegateFloat, UWatchedConsoleVariableFloat*, Variable);

