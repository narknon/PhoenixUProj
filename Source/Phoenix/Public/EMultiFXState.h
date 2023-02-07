#pragma once
#include "CoreMinimal.h"
#include "EMultiFXState.generated.h"

UENUM(BlueprintType)
enum class EMultiFXState : uint8 {
    Attacking,
    Arresto,
    BrokenOrDead,
    CombatCursed,
    Confundo,
    Disillusioned,
    Dodging,
    Frozen,
    InWater,
    Imperius,
    Invulnerable,
    Levioso,
    OnFire,
    Petrificus,
    Reacting,
    Revealed,
    RevealsThruWalls,
    Transformed,
    Vulnerable,
};

