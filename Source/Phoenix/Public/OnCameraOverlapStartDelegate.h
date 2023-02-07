#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnCameraOverlapStartDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCameraOverlapStart, FVector, Position);

