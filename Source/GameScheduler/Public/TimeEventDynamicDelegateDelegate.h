#pragma once
#include "CoreMinimal.h"
#include "TimeEvent.h"
#include "TimeEventDynamicDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FTimeEventDynamicDelegate, const FTimeEvent&, InTimeEvent);

