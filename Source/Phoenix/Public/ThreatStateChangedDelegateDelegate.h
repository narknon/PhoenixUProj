#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackThreatState.h"
#include "ThreatStateChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FThreatStateChangedDelegate, EEnemy_AttackThreatState, ThreatState);

