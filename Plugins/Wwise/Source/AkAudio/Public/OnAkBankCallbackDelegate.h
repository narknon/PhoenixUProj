#pragma once
#include "CoreMinimal.h"
#include "EAkResult.h"
#include "OnAkBankCallbackDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAkBankCallback, EAkResult, Result);

