#pragma once
#include "CoreMinimal.h"
#include "EForceRenderSettingsPhase.generated.h"

UENUM(BlueprintType)
enum class EForceRenderSettingsPhase : uint8 {
    Startup,
    BeginPlay,
    EndPlay,
};

