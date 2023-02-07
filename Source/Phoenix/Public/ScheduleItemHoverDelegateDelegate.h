#pragma once
#include "CoreMinimal.h"
#include "ScheduleItemHoverDelegateDelegate.generated.h"

class UScheduleItemWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FScheduleItemHoverDelegate, UScheduleItemWidget*, ScheduleItem);

