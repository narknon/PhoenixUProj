#pragma once
#include "CoreMinimal.h"
#include "OnItemBoolPropertyDragDetectedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemBoolPropertyDragDetected, const FString&, PropertyDragged);

