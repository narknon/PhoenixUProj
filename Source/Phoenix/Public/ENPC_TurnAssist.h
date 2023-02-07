#pragma once
#include "CoreMinimal.h"
#include "ENPC_TurnAssist.generated.h"

UENUM(BlueprintType)
enum class ENPC_TurnAssist : uint8 {
    None,
    Default,
    Mobility,
    MobilityStop,
    TurnInPlace,
    MobilityStart,
    Attack,
    Stomp,
    RunAt,
    Shuffle,
    Taunt,
    IdleBreak,
    AttackReset,
    TargetRelative,
    AlertPointOfInterest,
    AttackClose,
    ENPC_MAX UMETA(Hidden),
};

