#pragma once
#include "CoreMinimal.h"
#include "EWeatherSequenceOriginType.generated.h"

UENUM(BlueprintType)
enum class EWeatherSequenceOriginType : uint8 {
    Default,
    CustomLottery,
    Volume,
    CommandConsole,
    Override,
    Stack,
    SystemOverride,
};

