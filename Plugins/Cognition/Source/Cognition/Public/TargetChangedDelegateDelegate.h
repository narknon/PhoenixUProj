#pragma once
#include "CoreMinimal.h"
#include "TargetChangedDelegateDelegate.generated.h"

class AActor;
class UAISense;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTargetChangedDelegate, UAISense*, Sense, const AActor*, NewTarget, const AActor*, OldTarget);

