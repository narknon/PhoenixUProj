#pragma once
#include "CoreMinimal.h"
#include "CreatureMountChargeRefillDelayDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCreatureMountChargeRefillDelay, float, ChargeRefillDelayNormalized);

