#pragma once
#include "CoreMinimal.h"
#include "ESampleTextureToCurveType.generated.h"

UENUM(BlueprintType)
enum class ESampleTextureToCurveType : uint8 {
    SampleAlongU,
    SampleAlongV,
};

