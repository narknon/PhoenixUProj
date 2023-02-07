#pragma once
#include "CoreMinimal.h"
#include "EHighContrastGameplayBucket.generated.h"

UENUM(BlueprintType)
enum class EHighContrastGameplayBucket : uint8 {
    Player,
    Companion,
    FriendlyNPC,
    EnemyNPC,
    Item,
    Creature,
    Mount,
};

