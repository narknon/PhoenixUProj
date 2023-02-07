#pragma once
#include "CoreMinimal.h"
#include "HoverDroneToggleMiniMapDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHoverDroneToggleMiniMap, bool, bShowMiniMap);

