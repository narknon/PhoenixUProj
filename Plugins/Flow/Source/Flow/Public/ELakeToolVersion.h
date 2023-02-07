#pragma once
#include "CoreMinimal.h"
#include "ELakeToolVersion.generated.h"

UENUM(BlueprintType)
enum class ELakeToolVersion : uint8 {
    Base,
    FixWaterDepthEncoding,
    Latest = 0x1,
};

