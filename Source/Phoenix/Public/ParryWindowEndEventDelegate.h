#pragma once
#include "CoreMinimal.h"
#include "ParryWindowEndEventDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FParryWindowEndEvent, AActor*, InActorActor, bool, bInUnblockable);

