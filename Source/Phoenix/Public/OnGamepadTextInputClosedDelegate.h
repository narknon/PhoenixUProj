#pragma once
#include "CoreMinimal.h"
#include "EGamepadTextInputResult.h"
#include "OnGamepadTextInputClosedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGamepadTextInputClosed, TEnumAsByte<EGamepadTextInputResult>, InputResult, const FString&, TextEntry);

