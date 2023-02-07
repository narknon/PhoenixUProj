#pragma once
#include "CoreMinimal.h"
#include "ArrivedDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FArrivedDelegate, AActor*, Actor);

