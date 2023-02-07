#pragma once
#include "CoreMinimal.h"
#include "Int32ChangedDynamicDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInt32ChangedDynamicDelegate, int32, CachedResult);

