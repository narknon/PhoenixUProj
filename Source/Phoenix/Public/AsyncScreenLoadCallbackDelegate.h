#pragma once
#include "CoreMinimal.h"
#include "AsyncScreenLoadCallbackDelegate.generated.h"

class UScreen;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FAsyncScreenLoadCallback, UScreen*, LoadedScreen);

