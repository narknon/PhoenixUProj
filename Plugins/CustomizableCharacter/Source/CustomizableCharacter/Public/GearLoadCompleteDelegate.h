#pragma once
#include "CoreMinimal.h"
#include "GearLoadCompleteDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGearLoadComplete, AActor*, Actor, bool, bSuccess);

