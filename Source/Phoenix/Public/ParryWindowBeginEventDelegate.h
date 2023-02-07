#pragma once
#include "CoreMinimal.h"
#include "ParryWindowBeginEventDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FParryWindowBeginEvent, AActor*, InActorActor, bool, bInUnblockable);

