#pragma once
#include "CoreMinimal.h"
#include "OnPSOUpdateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPSOUpdate, float, Progress);

