#pragma once
#include "CoreMinimal.h"
#include "ButtonPressDelegateDelegate.generated.h"

class UIconButtonWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FButtonPressDelegate, UIconButtonWidget*, IconButton);

