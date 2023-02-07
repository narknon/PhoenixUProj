#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnPlayerOverlapStartDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerOverlapStart, AActor*, Target, FVector, Position);

