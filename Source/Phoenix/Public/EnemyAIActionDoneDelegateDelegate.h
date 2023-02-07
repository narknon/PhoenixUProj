#pragma once
#include "CoreMinimal.h"
#include "EEnemyAIAction.h"
#include "EEnemyAIActionDoneReason.h"
#include "EnemyAIActionDoneDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEnemyAIActionDoneDelegate, EEnemyAIAction, Action, EEnemyAIActionDoneReason, Reason);

