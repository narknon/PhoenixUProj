#pragma once
#include "CoreMinimal.h"
#include "DoneEventDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDoneEvent, AActor*, Actor);

