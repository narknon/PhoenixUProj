#pragma once
#include "CoreMinimal.h"
#include "EEnemyAIWeapon_Event.h"
#include "EnemyAIWeaponEventDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnemyAIWeaponEventDelegate, EEnemyAIWeapon_Event, Event);

