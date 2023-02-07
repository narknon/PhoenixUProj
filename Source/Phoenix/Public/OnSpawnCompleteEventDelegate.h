#pragma once
#include "CoreMinimal.h"
#include "OnSpawnCompleteEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSpawnCompleteEvent, const FString&, ObjectToLoad);

