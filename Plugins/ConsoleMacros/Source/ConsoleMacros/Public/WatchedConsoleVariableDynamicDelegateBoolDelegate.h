#pragma once
#include "CoreMinimal.h"
#include "WatchedConsoleVariableDynamicDelegateBoolDelegate.generated.h"

class UWatchedConsoleVariableBool;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWatchedConsoleVariableDynamicDelegateBool, UWatchedConsoleVariableBool*, Variable);

