#pragma once
#include "CoreMinimal.h"
#include "LegendInputHeldChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLegendInputHeldChanged, int32, LegendIndex, bool, HeldState);

