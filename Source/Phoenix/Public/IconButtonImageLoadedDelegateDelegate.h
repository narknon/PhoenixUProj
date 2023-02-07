#pragma once
#include "CoreMinimal.h"
#include "IconButtonImageLoadedDelegateDelegate.generated.h"

class UIconButtonWidget;
class UTexture2D;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIconButtonImageLoadedDelegate, UIconButtonWidget*, IconButton, UTexture2D*, LoadedTexture);

