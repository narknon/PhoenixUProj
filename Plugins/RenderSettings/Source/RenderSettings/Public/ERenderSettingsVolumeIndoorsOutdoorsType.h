#pragma once
#include "CoreMinimal.h"
#include "ERenderSettingsVolumeIndoorsOutdoorsType.generated.h"

UENUM(BlueprintType)
enum class ERenderSettingsVolumeIndoorsOutdoorsType : uint8 {
    IndoorsAndOutdoors,
    OutdoorsOnly,
    IndoorsOnly,
};

