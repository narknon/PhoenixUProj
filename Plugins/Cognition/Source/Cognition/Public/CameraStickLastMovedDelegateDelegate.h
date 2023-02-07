#pragma once
#include "CoreMinimal.h"
#include "CameraStickLastMovedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCameraStickLastMovedDelegate, bool, bCameraStickMoved);

