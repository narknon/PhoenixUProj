#pragma once
#include "CoreMinimal.h"
#include "ESpellDirection.generated.h"

UENUM(BlueprintType)
enum class ESpellDirection : uint8 {
    SpellDir_North,
    SpellDir_NorthEast,
    SpellDir_East,
    SpellDir_SouthEast,
    SpellDir_South,
    SpellDir_SouthWest,
    SpellDir_West,
    SpellDir_NorthWest,
    SpellDir_MAX UMETA(Hidden),
};

