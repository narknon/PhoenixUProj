#pragma once
#include "CoreMinimal.h"
#include "ETargetSpeedMode.h"
#include "TargetSpeedModeChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTargetSpeedModeChangedDelegate, TEnumAsByte<ETargetSpeedMode::Type>, TargetSpeedMode);

