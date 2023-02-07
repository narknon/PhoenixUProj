#pragma once
#include "CoreMinimal.h"
#include "TargetSightedDelegateDelegate.generated.h"

class AActor;
class UAISense;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTargetSightedDelegate, UAISense*, Sense, const AActor*, Target);

