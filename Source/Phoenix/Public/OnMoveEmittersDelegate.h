#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnMoveEmittersDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnMoveEmitters, FVector, Position, FVector, Velocity, bool, ACTIVE);

