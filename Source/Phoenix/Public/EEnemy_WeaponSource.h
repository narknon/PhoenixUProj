#pragma once
#include "CoreMinimal.h"
#include "EEnemy_WeaponSource.generated.h"

UENUM(BlueprintType)
enum class EEnemy_WeaponSource : uint8 {
    None,
    Active,
    Stored,
    Pickup,
    Transient,
    Required,
    EEnemy_MAX UMETA(Hidden),
};

