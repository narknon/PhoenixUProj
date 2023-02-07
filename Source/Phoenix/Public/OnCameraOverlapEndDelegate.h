#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnCameraOverlapEndDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCameraOverlapEnd, FVector, Position);

