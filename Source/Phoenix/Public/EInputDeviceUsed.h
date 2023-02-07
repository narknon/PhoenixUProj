#pragma once
#include "CoreMinimal.h"
#include "EInputDeviceUsed.generated.h"

UENUM(BlueprintType)
enum class EInputDeviceUsed : uint8 {
    None,
    KeyBoard_Mouse,
    Gamepad,
};

