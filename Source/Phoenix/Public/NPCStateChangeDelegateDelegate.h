#pragma once
#include "CoreMinimal.h"
#include "EEnemyAIState.h"
#include "NPCStateChangeDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNPCStateChangeDelegate, EEnemyAIState, State);

