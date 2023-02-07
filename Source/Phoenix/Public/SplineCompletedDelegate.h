#pragma once
#include "CoreMinimal.h"
#include "SplineCompletedDelegate.generated.h"

class UScheduledEntity;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSplineCompleted, UScheduledEntity*, ScheduledEntity, int32, ActivityTypeBits);

