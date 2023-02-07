#pragma once
#include "CoreMinimal.h"
#include "AddToManagerEventDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAddToManagerEvent, AActor*, InActorPtr);

