#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsRegionEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGlobalLightGroupsRegionEvent, FName, Region, bool, Activate);

