#pragma once
#include "CoreMinimal.h"
#include "EPIMTypes.generated.h"

UENUM(BlueprintType)
enum class EPIMTypes : uint8 {
    PressAccept,
    PressAndHoldAccept,
    JoystickClockwise,
    JoystickCounterClockwise,
    JoystickSmileyFace,
    JoystickWaggleLeftRight,
    JoystickLeft,
    JoystickRight,
    JoystickUp,
    JoystickDown,
    TelescopeFocus,
    SpellCast,
    PressWildcardAction,
};

