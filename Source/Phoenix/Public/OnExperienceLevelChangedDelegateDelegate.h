#pragma once
#include "CoreMinimal.h"
#include "OnExperienceLevelChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnExperienceLevelChangedDelegate, int32, ExpLevel, bool, bIndicateHUD);

