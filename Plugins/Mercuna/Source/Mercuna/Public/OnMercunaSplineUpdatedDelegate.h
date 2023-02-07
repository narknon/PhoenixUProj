#pragma once
#include "CoreMinimal.h"
#include "EMercunaSplineEvent.h"
#include "OnMercunaSplineUpdatedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMercunaSplineUpdated, TEnumAsByte<EMercunaSplineEvent::Type>, SplineEvent);

