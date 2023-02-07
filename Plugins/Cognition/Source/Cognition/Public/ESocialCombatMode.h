#pragma once
#include "CoreMinimal.h"
#include "ESocialCombatMode.generated.h"

UENUM(BlueprintType)
enum class ESocialCombatMode : uint8 {
    AllModes,
    Social,
    Combat,
    Adventure,
    Duress,
    Transfiguration,
};

