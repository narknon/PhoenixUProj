#pragma once
#include "CoreMinimal.h"
#include "GhostStoryEndedDelegateDelegate.generated.h"

class ASocialReasoning;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGhostStoryEndedDelegate, ASocialReasoning*, SocialReasoning, FName, SocialAction);

