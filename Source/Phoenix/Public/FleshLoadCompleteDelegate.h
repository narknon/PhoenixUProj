#pragma once
#include "CoreMinimal.h"
#include "FleshLoadCompleteDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFleshLoadComplete, AActor*, Actor);

