#pragma once
#include "CoreMinimal.h"
#include "PlayerSightedDelegateDelegate.generated.h"

class ASocialReasoning;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerSightedDelegate, const ASocialReasoning*, SocialReasoning);

