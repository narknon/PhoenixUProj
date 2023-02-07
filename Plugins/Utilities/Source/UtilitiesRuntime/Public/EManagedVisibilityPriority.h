#pragma once
#include "CoreMinimal.h"
#include "EManagedVisibilityPriority.generated.h"

UENUM(BlueprintType)
enum class EManagedVisibilityPriority : uint8 {
    Lowest,
    NpcShutdown,
    SceneRigDefault,
    PersistentVisibility,
    SeatFillerStartup,
    AsyncSpawn,
    OutOfView,
    InViewVisibility,
    HideTrigger,
    VisibilityTimeWindow,
    ForceHidden,
    WanderAndHide,
    HighestSystem,
    PassiveCinematic,
    ActiveCinematic,
    Highest,
    HardDestroyPriority,
};

