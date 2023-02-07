#pragma once
#include "CoreMinimal.h"
#include "InputWatcherFlushQueuedActionsDelegateDelegate.generated.h"

class UWatcherRecord;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInputWatcherFlushQueuedActionsDelegate, UWatcherRecord*, WatcherRecord);

