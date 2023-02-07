#pragma once
#include "CoreMinimal.h"
#include "EEnemyBuffTypeEnum.generated.h"

UENUM(BlueprintType)
enum class EEnemyBuffTypeEnum : uint8 {
    EBC_Health,
    EBC_WeaponRespawn,
    EBC_Random,
    EBC_MAX UMETA(Hidden),
};

