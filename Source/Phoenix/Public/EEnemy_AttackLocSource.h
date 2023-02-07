#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackLocSource.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackLocSource : uint8 {
    None,
    PieCut,
    Evade,
    Reposition,
    Close,
    SeekWeapon,
    Cover,
    Flee,
    Follow,
    Direct,
    InOut,
    Sidekick,
    Around,
    Retreat,
    SeekTarget,
    LeadPlayer,
    BackOnNav,
    TooClose,
    SwimToShore,
    Standby,
    Duel,
    Alert,
    Outside,
    Companion,
    Combat,
    RecoverWeapon,
    POI,
    Count,
    EEnemy_MAX UMETA(Hidden),
};

