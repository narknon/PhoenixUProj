#pragma once
#include "CoreMinimal.h"
#include "EReactionRotationSyncPointType.generated.h"

UENUM(BlueprintType)
enum class EReactionRotationSyncPointType : uint8 {
    Instigator,
    InstigatorInverse,
};

