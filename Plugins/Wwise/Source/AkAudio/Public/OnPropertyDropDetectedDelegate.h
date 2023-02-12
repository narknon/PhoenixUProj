#pragma once
#include "CoreMinimal.h"
#include "OnPropertyDropDetectedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPropertyDropDetected, const FString&, PropertyDropped);

