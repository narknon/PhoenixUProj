#pragma once
#include "CoreMinimal.h"
#include "FloatChangedDynamicDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFloatChangedDynamicDelegate, float, CachedResult);

