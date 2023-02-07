#pragma once
#include "CoreMinimal.h"
#include "WorldEventDataRow.h"
#include "OnWorldEventLevelLoadedDelegate.generated.h"

class AWorldEventLocationActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWorldEventLevelLoaded, AWorldEventLocationActor*, locationActor, const FWorldEventDataRow&, dataRow);

