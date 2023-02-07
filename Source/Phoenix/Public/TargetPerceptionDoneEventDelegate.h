#pragma once
#include "CoreMinimal.h"
#include "TargetPerceptionDoneEventDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTargetPerceptionDoneEvent, AActor*, Actor, bool, bSuccess, bool, bReturnControl);

