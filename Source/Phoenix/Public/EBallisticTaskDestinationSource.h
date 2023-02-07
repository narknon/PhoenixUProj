#pragma once
#include "CoreMinimal.h"
#include "EBallisticTaskDestinationSource.generated.h"

UENUM(BlueprintType)
enum class EBallisticTaskDestinationSource : uint8 {
    Stratchpad,
    FromTarget,
    ToTarget,
    ToLoc,
    ToParamLoc,
};

