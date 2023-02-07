#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NavigationPathUpdatedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNavigationPathUpdated, TArray<FVector>, NewPathPoints);

