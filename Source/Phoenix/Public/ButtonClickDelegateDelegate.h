#pragma once
#include "CoreMinimal.h"
#include "ButtonClickDelegateDelegate.generated.h"

class UIconButtonWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FButtonClickDelegate, UIconButtonWidget*, IconButton);

