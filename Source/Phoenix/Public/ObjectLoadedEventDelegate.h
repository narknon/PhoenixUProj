#pragma once
#include "CoreMinimal.h"
#include "ObjectLoadedEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FObjectLoadedEvent, const FString&, ObjectToLoad);

