#pragma once
#include "CoreMinimal.h"
#include "EForcedShutDownPriority.generated.h"

UENUM(BlueprintType)
enum class EForcedShutDownPriority : uint8 {
    None,
    ConversationPriority,
    StationPriority,
    CinematicPriority,
    HideTriggerPriority,
};

