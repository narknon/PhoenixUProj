#pragma once
#include "CoreMinimal.h"
#include "EEnemyAIAttackState.generated.h"

UENUM(BlueprintType)
enum class EEnemyAIAttackState : uint8 {
    None,
    Attack,
    Pressure,
    Withdraw,
    StayPut,
    CloseDistance,
    Cover,
    SeekWeapon,
    Evade,
    Follow,
    InOut,
    Reposition,
    SeekTarget,
    BackOnNav,
    LeadPlayer,
    TooClose,
    SwimToShore,
    Standby,
    Duel,
    TooCloseTeammate,
    Companion,
    Count,
};

