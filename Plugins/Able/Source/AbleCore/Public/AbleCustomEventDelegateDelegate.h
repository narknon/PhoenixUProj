#pragma once
#include "CoreMinimal.h"
#include "AbleCustomEventDelegateDelegate.generated.h"

class UAblAbilityContext;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAbleCustomEventDelegate, const UAblAbilityContext*, Context, const UAblAbilityContext*, CallerContext, FName, EventName);

