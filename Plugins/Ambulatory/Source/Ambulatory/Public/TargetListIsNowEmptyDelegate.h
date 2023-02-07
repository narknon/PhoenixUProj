#pragma once
#include "CoreMinimal.h"
#include "ETargetID.h"
#include "ETargetType.h"
#include "TargetListIsNowEmptyDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTargetListIsNowEmpty, TEnumAsByte<ETargetType::Type>, LastTargetType, TEnumAsByte<ETargetID::Type>, LastTargetID);

