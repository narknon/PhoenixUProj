#pragma once
#include "CoreMinimal.h"
#include "EBossStates.h"
#include "BossFightEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBossFightEvent, FName, InBossFightName, EBossStates, InBossFightState);

