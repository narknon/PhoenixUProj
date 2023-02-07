#pragma once
#include "CoreMinimal.h"
#include "ESchedulingPriority.generated.h"

UENUM(BlueprintType)
enum class ESchedulingPriority : uint8 {
    ScheduledEntityPriority,
    BluePrintPriority,
    CompanionPriority,
    NonCombatPriority,
    NPCPriority,
    EnemyPriority,
    CinematicPriority,
    SystemPriority,
    TransientAction,
    ShutdownPriority,
    ForcedShutdownPriority,
};

