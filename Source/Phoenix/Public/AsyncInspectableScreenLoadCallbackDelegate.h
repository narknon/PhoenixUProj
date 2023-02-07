#pragma once
#include "CoreMinimal.h"
#include "AsyncInspectableScreenLoadCallbackDelegate.generated.h"

class UScreen;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_OneParam(FAsyncInspectableScreenLoadCallback, TSoftObjectPtr<UScreen>, LoadedScreen);

