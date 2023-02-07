#pragma once
#include "CoreMinimal.h"
#include "CreatureMountChargeAmountDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCreatureMountChargeAmount, float, ChargeAmountNormalized, bool, bChargeAvailable);

