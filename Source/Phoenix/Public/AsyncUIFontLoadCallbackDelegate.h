#pragma once
#include "CoreMinimal.h"
#include "AsyncUIFontLoadCallbackDelegate.generated.h"

class UFont;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FAsyncUIFontLoadCallback, UFont*, LoadedFont);

