#pragma once
#include "CoreMinimal.h"
#include "AkMultiPositionType.generated.h"

UENUM(BlueprintType)
enum class AkMultiPositionType : uint8 {
    SingleSource,
    MultiSources,
    MultiDirections,
};

