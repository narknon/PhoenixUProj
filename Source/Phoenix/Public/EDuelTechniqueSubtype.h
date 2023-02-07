#pragma once
#include "CoreMinimal.h"
#include "EDuelTechniqueSubtype.generated.h"

UENUM(BlueprintType)
enum class EDuelTechniqueSubtype : uint8 {
    Damage,
    Reaction,
    Depulso,
    TimedEncounter,
    Combo,
    CustomEvent,
    KillAllEnemies,
    Deflect,
    Oppugno,
    SpellEffect,
    TimedJuggle,
    ComboCount,
    SpellEffectMultiple,
    ImperiusKill,
    NoHealthItem,
};

