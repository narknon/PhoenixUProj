#pragma once
#include "CoreMinimal.h"
#include "EGfeSDKReturnCode.h"
#include "GfeSDKCreateResponse.h"
#include "OnHighlightsInitCallbackDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHighlightsInitCallback, EGfeSDKReturnCode, GfeSdkReturnCode, FGfeSDKCreateResponse, GfeSdkProperties);

