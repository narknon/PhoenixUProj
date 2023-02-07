#pragma once
#include "CoreMinimal.h"
#include "EWandLinkState.generated.h"

UENUM(BlueprintType)
enum class EWandLinkState : uint8 {
    None,
    Start,
    Defend,
    ProtagonistSurge,
    AntagonistSurge,
};

