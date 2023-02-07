#pragma once
#include "CoreMinimal.h"
#include "RemoveFromManagerEventDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRemoveFromManagerEvent, AActor*, InActorPtr);

