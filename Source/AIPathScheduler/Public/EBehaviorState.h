#pragma once
#include "CoreMinimal.h"
#include "EBehaviorState.generated.h"

UENUM(BlueprintType)
enum class EBehaviorState : uint8 {
    Simulated,
    Restarting,
    Alive,
    Reacting_MoveToStation,
    Reacting_MoveToSpline,
    Reacting,
    Dormant,
    Paused,
    WalkToStation,
    WalkToSpline,
    RefreshSplineData,
    Spawning,
    Destroyed,
    RenderShutdown,
    FormGroup,
    Transferred,
};

