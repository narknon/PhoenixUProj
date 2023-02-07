#pragma once
#include "CoreMinimal.h"
#include "HealthThreshold.h"
#include "HealthThresholdReachedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FHealthThresholdReachedDelegate, FHealthThreshold, HealthThreshold, int32, Level, int32, MaxLevel);

