#pragma once
#include "CoreMinimal.h"
#include "EDayNightEventDirectionTrigger.generated.h"

UENUM(BlueprintType)
enum class EDayNightEventDirectionTrigger : uint8 {
    Rising,
    Setting,
    RisingAndSetting,
};

