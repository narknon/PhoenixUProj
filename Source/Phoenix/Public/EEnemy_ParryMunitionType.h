#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ParryMunitionType.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ParryMunitionType : uint8 {
    None,
    Weapon,
    Spell,
    Ballistic,
    Melee,
    Custom,
    External,
    RunTo,
    EEnemy_MAX UMETA(Hidden),
};

