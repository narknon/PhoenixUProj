#pragma once
#include "CoreMinimal.h"
#include "AkOnFloatValueChangedEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAkOnFloatValueChangedEvent, float, Value);

