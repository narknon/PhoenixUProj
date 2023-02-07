#pragma once
#include "CoreMinimal.h"
#include "ERPGModInputTags.generated.h"

UENUM()
enum class ERPGModInputTags : int32 {
    XPLevel,
    ItemEffectiveness,
    OffenseStat,
    DefenseStat,
    CooldownStat,
    StatDamageMultiplier,
    StatDamageReduction,
    StatCooldownReduction,
    LastHealAmount,
    PotionEffectCounter,
    ComboFocusMultiplier,
    NumTags,
};

