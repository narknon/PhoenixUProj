#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterLoadingBundleAndSwapStateDynamicDelegateDelegate.generated.h"

class AActor;
class UMaterialPermuterLoadingBundleAndSwap;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FMaterialPermuterLoadingBundleAndSwapStateDynamicDelegate, const UMaterialPermuterLoadingBundleAndSwap*, Bundle, AActor*, Actor, bool, bSwapped);

