#pragma once
#include "CoreMinimal.h"
#include "PerformTask_WaitForPlayerDelegate.generated.h"

class ASocialReasoning;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPerformTask_WaitForPlayer, const ASocialReasoning*, SocialReasoning);

