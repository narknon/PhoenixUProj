#pragma once
#include "CoreMinimal.h"
#include "CameraStickTimerExpiredDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCameraStickTimerExpired, bool&, bCanReset);

