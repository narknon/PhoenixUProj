#pragma once
#include "CoreMinimal.h"
#include "ETargetID.h"
#include "ETargetType.h"
#include "TargetHasNewBestTargetDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTargetHasNewBestTarget, TEnumAsByte<ETargetType::Type>, NewTargetType, TEnumAsByte<ETargetID::Type>, NewTargetID);

