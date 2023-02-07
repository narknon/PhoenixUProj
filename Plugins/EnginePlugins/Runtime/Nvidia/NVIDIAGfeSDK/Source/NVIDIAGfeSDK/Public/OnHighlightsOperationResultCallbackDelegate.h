#pragma once
#include "CoreMinimal.h"
#include "EGfeSDKReturnCode.h"
#include "OnHighlightsOperationResultCallbackDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHighlightsOperationResultCallback, EGfeSDKReturnCode, GfeSdkReturnCode);

