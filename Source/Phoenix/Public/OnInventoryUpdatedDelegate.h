#pragma once
#include "CoreMinimal.h"
#include "OnInventoryUpdatedDelegate.generated.h"

class UObject;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryUpdated, const UObject*, i_caller);

