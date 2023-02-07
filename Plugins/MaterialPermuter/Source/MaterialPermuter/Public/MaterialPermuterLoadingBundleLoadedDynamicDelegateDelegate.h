#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterLoadingBundleLoadedDynamicDelegateDelegate.generated.h"

class UMaterialPermuterLoadingBundle;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMaterialPermuterLoadingBundleLoadedDynamicDelegate, UMaterialPermuterLoadingBundle*, Bundle);

