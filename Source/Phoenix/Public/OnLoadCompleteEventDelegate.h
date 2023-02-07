#pragma once
#include "CoreMinimal.h"
#include "OnLoadCompleteEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoadCompleteEvent, const FString&, ObjectToLoad);

