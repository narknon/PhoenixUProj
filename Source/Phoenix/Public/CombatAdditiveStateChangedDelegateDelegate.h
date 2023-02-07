#pragma once
#include "CoreMinimal.h"
#include "ECombatAdditiveState.h"
#include "CombatAdditiveStateChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCombatAdditiveStateChangedDelegate, TEnumAsByte<ECombatAdditiveState::Type>, CombatAdditiveState);

