#pragma once
#include "CoreMinimal.h"
#include "ButtonUnhoverDelegateDelegate.generated.h"

class UIconButtonWidget;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FButtonUnhoverDelegate, UIconButtonWidget*, IconButton);

