#pragma once
#include "CoreMinimal.h"
#include "AKWaapiJsonObject.h"
#include "AkWaapiSubscriptionId.h"
#include "OnEventCallbackDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnEventCallback, FAkWaapiSubscriptionId, SubscriptionId, FAKWaapiJsonObject, WaapiJsonObject);

