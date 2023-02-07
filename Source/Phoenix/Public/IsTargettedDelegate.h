#pragma once
#include "CoreMinimal.h"
#include "IsTargettedDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIsTargetted, const AActor*, Actor);

