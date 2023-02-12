#pragma once
#include "CoreMinimal.h"
#include "OnItemPropertyDragDetectedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemPropertyDragDetected, const FString&, PropertyDragged);

