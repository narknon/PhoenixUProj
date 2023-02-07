#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackApparateMode.generated.h"

UENUM(BlueprintType)
enum class EEnemy_AttackApparateMode : uint8 {
    None,
    Target,
    Player,
    Self,
    Location,
    Custom,
    EEnemy_MAX UMETA(Hidden),
};

