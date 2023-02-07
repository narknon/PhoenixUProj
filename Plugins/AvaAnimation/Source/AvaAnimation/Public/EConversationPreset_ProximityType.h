#pragma once
#include "CoreMinimal.h"
#include "EConversationPreset_ProximityType.generated.h"

UENUM()
enum class EConversationPreset_ProximityType : int8 {
    Ideal,
    Near,
    TooClose,
    EConversationPreset_MAX UMETA(Hidden),
};

