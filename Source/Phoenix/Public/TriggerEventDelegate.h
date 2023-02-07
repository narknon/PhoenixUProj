#pragma once
#include "CoreMinimal.h"
#include "TriggerEventDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_DELEGATE_TwoParams(FTriggerEvent, AActor*, TriggerActor, int32, EventSplinePointIndex);

