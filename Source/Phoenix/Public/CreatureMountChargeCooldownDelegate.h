#pragma once
#include "CoreMinimal.h"
#include "CreatureMountChargeCooldownDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCreatureMountChargeCooldown, float, ChargeCooldownNormalized);

