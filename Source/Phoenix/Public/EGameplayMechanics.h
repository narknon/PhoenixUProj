#pragma once
#include "CoreMinimal.h"
#include "EGameplayMechanics.generated.h"

UENUM(BlueprintType)
enum class EGameplayMechanics : uint8 {
    Move,
    Jump,
    DodgeRoll,
    Protego,
    LightCast,
    HeavyCast,
    Revelio,
    MapHelp,
    ItemMenu,
    AimMode,
    Finishers,
    Oppugno,
    AutoTarget,
};

