#pragma once
#include "CoreMinimal.h"
#include "EHoverDroneControlMode.h"
#include "HoverDroneControlModeChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHoverDroneControlModeChanged, TEnumAsByte<EHoverDroneControlMode::Type>, ControlMode);

