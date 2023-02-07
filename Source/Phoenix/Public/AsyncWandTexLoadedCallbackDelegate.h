#pragma once
#include "CoreMinimal.h"
#include "AsyncWandTexLoadedCallbackDelegate.generated.h"

class UTexture;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FAsyncWandTexLoadedCallback, UTexture*, LoadedTexture, const FName, TexParam);

