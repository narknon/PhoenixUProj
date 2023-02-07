#pragma once
#include "CoreMinimal.h"
#include "EGamepadTextInputResult.h"
#include "OnFloatingGamepadTextInputClosedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFloatingGamepadTextInputClosed, TEnumAsByte<EGamepadTextInputResult>, InputResult);

