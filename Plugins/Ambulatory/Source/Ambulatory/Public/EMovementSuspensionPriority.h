#pragma once
#include "CoreMinimal.h"
#include "EMovementSuspensionPriority.generated.h"

UENUM(BlueprintType)
enum class EMovementSuspensionPriority : uint8 {
    Lowest,
    SE_RenderShutdown,
    NPC_Shutdown,
    StationEnter,
    BroomFlight,
    PassiveCinematic,
    ActiveCinematic,
    Highest,
};

