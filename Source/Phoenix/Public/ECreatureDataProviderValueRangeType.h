#pragma once
#include "CoreMinimal.h"
#include "ECreatureDataProviderValueRangeType.generated.h"

UENUM()
enum class ECreatureDataProviderValueRangeType : int32 {
    Min,
    Max,
    Random,
};

