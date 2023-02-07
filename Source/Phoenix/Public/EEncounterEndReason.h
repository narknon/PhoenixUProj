#pragma once
#include "CoreMinimal.h"
#include "EEncounterEndReason.generated.h"

UENUM()
enum class EEncounterEndReason : int8 {
    NoCombatVolume_NoAggro,
    CombatVolume_Escaped,
    CombatVolume_Completed,
};

