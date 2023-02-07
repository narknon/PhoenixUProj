#pragma once
#include "CoreMinimal.h"
#include "EEnemySplineSpawnEffectType.generated.h"

UENUM(BlueprintType)
enum class EEnemySplineSpawnEffectType : uint8 {
    None,
    Faction,
    Shield,
    Num,
};

