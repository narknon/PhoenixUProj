#pragma once
#include "CoreMinimal.h"
#include "OnDeadDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeadDelegate, AActor*, pActor);

