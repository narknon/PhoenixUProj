#pragma once
#include "CoreMinimal.h"
#include "ButtonReleaseDelegateDelegate.generated.h"

class UIconButtonWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FButtonReleaseDelegate, UIconButtonWidget*, IconButton);

