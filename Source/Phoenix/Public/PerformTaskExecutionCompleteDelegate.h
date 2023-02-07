#pragma once
#include "CoreMinimal.h"
#include "PerformTaskExecutionCompleteDelegate.generated.h"

class UScheduledEntity;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPerformTaskExecutionComplete, UScheduledEntity*, ScheduledEntity, int32, ActivityTypeBits);

