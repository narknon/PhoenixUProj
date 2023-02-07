#pragma once
#include "CoreMinimal.h"
#include "TimeEvent.h"
#include "ThinkDelegateDelegate.generated.h"

class ASocialReasoning;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FThinkDelegate, const ASocialReasoning*, SocialReasoning, const FTimeEvent&, TimeEvent);

