#pragma once
#include "CoreMinimal.h"
#include "QueueReactionParams.h"
#include "ReactionParamsDelegateDelegate.generated.h"

class UAblReactionComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FReactionParamsDelegate, const FQueueReactionParams&, ReactionParams, UAblReactionComponent*, ReactionComponent);

