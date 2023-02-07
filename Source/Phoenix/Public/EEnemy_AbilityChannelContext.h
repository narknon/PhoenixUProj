#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AbilityChannelContext.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AbilityChannelContext : uint8 {
    HasWeapon,
    HasShield,
    Unaware,
    Alert,
    Attack,
    IsBlind,
    IsInjured,
    EEnemy_MAX UMETA(Hidden),
};

