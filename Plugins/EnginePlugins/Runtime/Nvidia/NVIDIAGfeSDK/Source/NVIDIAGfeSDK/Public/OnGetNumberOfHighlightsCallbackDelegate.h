#pragma once
#include "CoreMinimal.h"
#include "EGfeSDKReturnCode.h"
#include "OnGetNumberOfHighlightsCallbackDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetNumberOfHighlightsCallback, EGfeSDKReturnCode, GfeSdkReturnCode, int32, NumberOfHighlights);

