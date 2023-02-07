#pragma once
#include "CoreMinimal.h"
#include "ButtonHoverDelegateDelegate.generated.h"

class UIconButtonWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FButtonHoverDelegate, UIconButtonWidget*, IconButton);

