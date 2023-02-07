#pragma once
#include "CoreMinimal.h"
#include "EVoiceOverCompanionSelection.generated.h"

UENUM(BlueprintType)
enum class EVoiceOverCompanionSelection : uint8 {
    ForcedOrAnySystemic,
    AnyCompanion,
    PrimaryCompanion,
    ForcedCompanion,
    SystemicCompanion,
};

