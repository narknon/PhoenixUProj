#pragma once
#include "CoreMinimal.h"
#include "ENPC_LOSUserType.generated.h"

UENUM(BlueprintType)
enum class ENPC_LOSUserType : uint8 {
    None,
    EnemyToTarget,
    AttackLocToTarget,
    Shuffle,
    Waypoint,
    Retreat,
    BackOnNav,
    ENPC_MAX UMETA(Hidden),
};

