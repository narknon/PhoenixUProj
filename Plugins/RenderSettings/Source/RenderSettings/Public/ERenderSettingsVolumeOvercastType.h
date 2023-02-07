#pragma once
#include "CoreMinimal.h"
#include "ERenderSettingsVolumeOvercastType.generated.h"

UENUM(BlueprintType)
enum class ERenderSettingsVolumeOvercastType : uint8 {
    ClearAndOvercast,
    ClearOnly,
    OvercastOnly,
};

