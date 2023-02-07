#pragma once
#include "CoreMinimal.h"
#include "TargetLostDelegateDelegate.generated.h"

class AActor;
class UAISense;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTargetLostDelegate, UAISense*, Sense, const AActor*, OldTarget);

