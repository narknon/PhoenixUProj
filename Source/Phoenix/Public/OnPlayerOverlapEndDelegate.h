#pragma once
#include "CoreMinimal.h"
#include "OnPlayerOverlapEndDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerOverlapEnd, AActor*, Target);

