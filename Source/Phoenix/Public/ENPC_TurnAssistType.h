#pragma once
#include "CoreMinimal.h"
#include "ENPC_TurnAssistType.generated.h"

UENUM(BlueprintType)
enum class ENPC_TurnAssistType : uint8 {
    None,
    Fixed,
    Target,
    Instigator,
    Player,
    TargetRelative,
    ExternalMode,
    TargetTracker,
    MovementDirection,
    ENPC_MAX UMETA(Hidden),
};

