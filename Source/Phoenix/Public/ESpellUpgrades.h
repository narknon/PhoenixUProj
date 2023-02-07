#pragma once
#include "CoreMinimal.h"
#include "ESpellUpgrades.generated.h"

UENUM(BlueprintType)
enum class ESpellUpgrades : uint8 {
    UpgradedMechanic,
    Maxima,
    IncrementLimitedCount,
    AffectCharacters,
    Unblockable,
    BreakBlockUnaware,
    BreakBlockPygmyPerk,
    Curse,
    WeakenNonLiftable,
    Popup,
    Projectiles,
    IncreasedCharacterDuration,
    AOE,
    PerfectProtegoUnblockable,
    ProtegoAOE,
    ProtegoDamage,
    ProtegoFocusGain,
    CrucioHeals,
    ImperiusAllyDamage,
    BombardaCooldown,
};

