#pragma once
#include "CoreMinimal.h"
#include "OnItemBoolPropertySelectionChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemBoolPropertySelectionChanged, const FString&, PropertySelected);

