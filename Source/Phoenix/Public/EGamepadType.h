#pragma once
#include "CoreMinimal.h"
#include "EGamepadType.generated.h"

UENUM(BlueprintType)
enum EGamepadType {
    Gamepad_XboxOne,
    Gamepad_PS4,
    Gamepad_PS5,
    Gamepad_Switch,
    Gamepad_Steam,
    Gamepad_Misc = 0x0,
    Gamepad_MAX = 0x5,
};

