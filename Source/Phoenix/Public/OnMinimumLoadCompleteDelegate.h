#pragma once
#include "CoreMinimal.h"
#include "OnMinimumLoadCompleteDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMinimumLoadComplete, FName, ZoneName);

