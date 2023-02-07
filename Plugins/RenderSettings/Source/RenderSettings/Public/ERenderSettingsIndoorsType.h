#pragma once
#include "CoreMinimal.h"
#include "ERenderSettingsIndoorsType.generated.h"

UENUM(BlueprintType)
enum class ERenderSettingsIndoorsType : uint8 {
    Indoors,
    SmoothedIndoors,
    ProbeIndoors,
    SmoothedProbeIndoors,
    StreamingIndoors,
};

