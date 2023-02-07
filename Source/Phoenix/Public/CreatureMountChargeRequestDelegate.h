#pragma once
#include "CoreMinimal.h"
#include "CreatureMountChargeRequestDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCreatureMountChargeRequest, float, ChargeRequestNormalized);

