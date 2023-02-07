#pragma once
#include "CoreMinimal.h"
#include "ESEEnsureHighLODPriority.generated.h"

UENUM(BlueprintType)
enum class ESEEnsureHighLODPriority : uint8 {
    Companion,
    PassiveCinematic,
    ActiveCinematic,
    PerformTask,
    Creature,
    AuthorityFigure,
    SeatFiller,
    BroomFlight,
    Apparate,
};

