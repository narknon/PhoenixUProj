#pragma once
#include "CoreMinimal.h"
#include "StateEffectComponentEndEffectDelegate.generated.h"

class UActorComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStateEffectComponentEndEffect, UActorComponent*, Component);

