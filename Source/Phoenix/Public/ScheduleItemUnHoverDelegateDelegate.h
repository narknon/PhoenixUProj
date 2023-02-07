#pragma once
#include "CoreMinimal.h"
#include "ScheduleItemUnHoverDelegateDelegate.generated.h"

class UScheduleItemWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FScheduleItemUnHoverDelegate, UScheduleItemWidget*, ScheduleItem);

