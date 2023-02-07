#pragma once
#include "CoreMinimal.h"
#include "ESEPrecacheFleshPriority.generated.h"

UENUM(BlueprintType)
enum class ESEPrecacheFleshPriority : uint8 {
    CachedPriority,
    BluePrintPriority,
    PerformTaskPriority,
    CompanionPriority,
    MissionPriority,
    ConversationPriority,
    CinematicPriority,
};

