#pragma once
#include "CoreMinimal.h"
#include "ECharacterShutdownPriority.generated.h"

UENUM(BlueprintType)
enum class ECharacterShutdownPriority : uint8 {
    Lowest,
    PreventStrike,
    InStation,
    NPCOptimization,
    NPCTeleport,
    InCinematic,
    InFinisher,
    SpecialClearAndPrevent,
    SpecialSpawning,
    NonRender,
    FleshCache,
};

