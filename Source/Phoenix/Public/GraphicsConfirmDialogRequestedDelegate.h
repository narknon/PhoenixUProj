#pragma once
#include "CoreMinimal.h"
#include "GraphicsConfirmDialogRequestedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGraphicsConfirmDialogRequested, float, Duration);

