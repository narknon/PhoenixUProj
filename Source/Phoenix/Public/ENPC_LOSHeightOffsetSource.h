#pragma once
#include "CoreMinimal.h"
#include "ENPC_LOSHeightOffsetSource.generated.h"

UENUM(BlueprintType)
enum class ENPC_LOSHeightOffsetSource : uint8 {
    Ground,
    Loc,
    ENPC_MAX UMETA(Hidden),
};

