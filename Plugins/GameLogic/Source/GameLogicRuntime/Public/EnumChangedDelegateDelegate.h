#pragma once
#include "CoreMinimal.h"
#include "EnumChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnumChangedDelegate, uint8, CachedResult);

