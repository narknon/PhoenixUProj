#pragma once
#include "CoreMinimal.h"
#include "HardSwapBatchComponentDoneDynamicDelegateDelegate.generated.h"

class UHardSwapBatchComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHardSwapBatchComponentDoneDynamicDelegate, UHardSwapBatchComponent*, HardSwapBatchComponent);

