#pragma once
#include "CoreMinimal.h"
#include "OnFullGameNotInstalledPopupClosedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFullGameNotInstalledPopupClosed, bool, continueToGame);

