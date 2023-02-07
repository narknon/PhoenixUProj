#pragma once
#include "CoreMinimal.h"
#include "EReactionLocationSyncPointType.generated.h"

UENUM(BlueprintType)
enum class EReactionLocationSyncPointType : uint8 {
    Instigator,
    TargetPosition,
};

