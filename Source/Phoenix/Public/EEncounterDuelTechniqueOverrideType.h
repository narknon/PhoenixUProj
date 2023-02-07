#pragma once
#include "CoreMinimal.h"
#include "EEncounterDuelTechniqueOverrideType.generated.h"

UENUM()
enum class EEncounterDuelTechniqueOverrideType : int8 {
    AlwaysSelectIfValid,
    AlwaysSelectEvenIfInvalid,
    PreferStronglyToSelect,
    PreferLooselyToSelect,
    PreferLooselyToAvoid,
    PreferStronglyToAvoid,
    NeverSelect,
};

