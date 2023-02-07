#pragma once
#include "CoreMinimal.h"
#include "EEnemy_Ability.h"
#include "DynamicBranchBeginAbilityDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDynamicBranchBeginAbility, EEnemy_Ability, EnemyAbility);

