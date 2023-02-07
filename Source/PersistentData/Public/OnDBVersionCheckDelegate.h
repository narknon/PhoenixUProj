#pragma once
#include "CoreMinimal.h"
#include "OnDBVersionCheckDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDBVersionCheck, const int32, DBVersion, const int32, DBChangeList);

