#pragma once
#include "CoreMinimal.h"
#include "ECursorControlTypes.generated.h"

UENUM(BlueprintType)
namespace ECursorControlTypes {
    enum Type {
        CURSOR_CONTROL_AUTO,
        CURSOR_CONTROL_GAMEPAD,
        CURSOR_CONTROL_MOUSE,
        CURSOR_CONTROL_MAX UMETA(Hidden),
    };
}

