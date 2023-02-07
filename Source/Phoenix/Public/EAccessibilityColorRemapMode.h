#pragma once
#include "CoreMinimal.h"
#include "EAccessibilityColorRemapMode.generated.h"

UENUM(BlueprintType)
enum class EAccessibilityColorRemapMode : uint8 {
    Invalid,
    Initialize,
    None,
    Deuteranope,
    Protanope,
    Tritanope,
};

