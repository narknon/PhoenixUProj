#pragma once
#include "CoreMinimal.h"
#include "LegendItemData.h"
#include "NewButtonLegendRequestedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNewButtonLegendRequested, const TArray<FLegendItemData>&, NewLegend);

