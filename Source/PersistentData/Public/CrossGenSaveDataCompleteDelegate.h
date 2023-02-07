#pragma once
#include "CoreMinimal.h"
#include "CrossGenSaveDataCompleteDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCrossGenSaveDataComplete, bool, bResult);

