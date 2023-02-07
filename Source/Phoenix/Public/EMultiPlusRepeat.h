#pragma once
#include "CoreMinimal.h"
#include "EMultiPlusRepeat.generated.h"

UENUM(BlueprintType)
enum class EMultiPlusRepeat : uint8 {
    Standard,
    Restart,
    Ignore,
};

