#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterLoadType.generated.h"

UENUM(BlueprintType)
enum class EMaterialPermuterLoadType : uint8 {
    Preload,
    Manual,
    Auto,
    TriggerOnly,
    TriggerAndAuto,
    TriggerAndManual,
};

