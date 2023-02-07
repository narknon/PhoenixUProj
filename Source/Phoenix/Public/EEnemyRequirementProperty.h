#pragma once
#include "CoreMinimal.h"
#include "EEnemyRequirementProperty.generated.h"

UENUM(BlueprintType)
enum class EEnemyRequirementProperty : uint8 {
    None,
    Juggleable,
    Freezable,
    Burnable,
    Transformable,
    Blockable,
    Unshielded,
};

