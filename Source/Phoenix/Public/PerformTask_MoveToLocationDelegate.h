#pragma once
#include "CoreMinimal.h"
#include "PerformTask_MoveToLocationDelegate.generated.h"

class ASocialReasoning;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPerformTask_MoveToLocation, const ASocialReasoning*, SocialReasoning);

