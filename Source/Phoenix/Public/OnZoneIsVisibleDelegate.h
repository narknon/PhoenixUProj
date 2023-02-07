#pragma once
#include "CoreMinimal.h"
#include "OnZoneIsVisibleDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnZoneIsVisible, FName, ZoneName);

