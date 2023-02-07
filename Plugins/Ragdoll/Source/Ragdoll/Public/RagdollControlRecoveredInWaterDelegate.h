#pragma once
#include "CoreMinimal.h"
#include "RagdollControlRecoveredInWaterDelegate.generated.h"

class URagdollControlComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRagdollControlRecoveredInWater, URagdollControlComponent*, RagdollControlComponent);

