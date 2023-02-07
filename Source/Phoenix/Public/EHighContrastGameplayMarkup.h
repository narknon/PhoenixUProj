#pragma once
#include "CoreMinimal.h"
#include "EHighContrastGameplayMarkup.generated.h"

UENUM(BlueprintType)
enum class EHighContrastGameplayMarkup : uint8 {
    None,
    Player,
    Companion,
    FriendlyNPC,
    EnemyNPC,
    Item,
    Creature,
    Mount,
    RevelioItem,
    RevelioImportant,
    RevelioEnemy,
    ShieldPurple,
    ShieldOrange,
    ShieldRed,
    ShieldWhite,
    ShieldBlue,
};

