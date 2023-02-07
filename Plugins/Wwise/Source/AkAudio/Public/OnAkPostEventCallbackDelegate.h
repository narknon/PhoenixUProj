#pragma once
#include "CoreMinimal.h"
#include "EAkCallbackType.h"
#include "OnAkPostEventCallbackDelegate.generated.h"

class UAkCallbackInfo;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnAkPostEventCallback, EAkCallbackType, CallbackType, UAkCallbackInfo*, CallbackInfo);

