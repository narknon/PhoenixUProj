#pragma once
#include "CoreMinimal.h"
#include "EEnemyAIWeapon_Event.generated.h"

UENUM(BlueprintType)
enum class EEnemyAIWeapon_Event : uint8 {
    None,
    TombProtectorMeteor_Choose,
    TombProtectorMeteor_Break,
    TombProtectorMeteor_Throw,
    EEnemyAIWeapon_MAX UMETA(Hidden),
};

