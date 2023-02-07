#pragma once
#include "CoreMinimal.h"
#include "OnActiveIslandSetDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActiveIslandSet, FName, IslandName);

