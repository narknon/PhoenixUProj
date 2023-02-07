#pragma once
#include "CoreMinimal.h"
#include "EPerformTaskCombatMode.generated.h"

UENUM(BlueprintType)
enum class EPerformTaskCombatMode : uint8 {
    Normal,
    Protector,
    Custom,
    DuelOpponent,
    FightClubOpponent,
    Aggressor,
    GroupAggressor,
};

