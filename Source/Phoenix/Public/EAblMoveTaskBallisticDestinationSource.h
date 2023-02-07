#pragma once
#include "CoreMinimal.h"
#include "EAblMoveTaskBallisticDestinationSource.generated.h"

UENUM(BlueprintType)
enum class EAblMoveTaskBallisticDestinationSource : uint8 {
    Stratchpad,
    FromTarget,
    ToTarget,
    ToLoc,
    ToParamLoc,
};

