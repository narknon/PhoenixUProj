#pragma once
#include "CoreMinimal.h"
#include "HardSwapBatchComponentActorSwappedDynamicDelegateDelegate.generated.h"

class AActor;
class UHardSwapBatchComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FHardSwapBatchComponentActorSwappedDynamicDelegate, UHardSwapBatchComponent*, HardSwapBatchComponent, AActor*, Actor, int32, MaterialSwaps);

