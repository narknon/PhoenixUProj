#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterLoadingBundlePercentageDynamicDelegateDelegate.generated.h"

class UMaterialPermuterLoadingBundle;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMaterialPermuterLoadingBundlePercentageDynamicDelegate, UMaterialPermuterLoadingBundle*, Bundle, float, PercentLoaded);

