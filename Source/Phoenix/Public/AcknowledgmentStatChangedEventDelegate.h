#pragma once
#include "CoreMinimal.h"
#include "AcknowledgmentStatChangedEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAcknowledgmentStatChangedEvent, FName, Key, int32, Value, int32, Delta);

