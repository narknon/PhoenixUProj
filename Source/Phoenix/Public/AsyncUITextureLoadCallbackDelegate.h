#pragma once
#include "CoreMinimal.h"
#include "AsyncUITextureLoadCallbackDelegate.generated.h"

class UObject;
class UTexture2D;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FAsyncUITextureLoadCallback, UTexture2D*, LoadedTexture, UObject*, CallbackParam);

