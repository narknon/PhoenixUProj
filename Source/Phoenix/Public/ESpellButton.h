#pragma once
#include "CoreMinimal.h"
#include "ESpellButton.generated.h"

UENUM(BlueprintType)
enum class ESpellButton : uint8 {
    SPELL_TOP,
    SPELL_BOTTOM,
    SPELL_LEFT,
    SPELL_RIGHT,
    SPELL_MAX UMETA(Hidden),
};

