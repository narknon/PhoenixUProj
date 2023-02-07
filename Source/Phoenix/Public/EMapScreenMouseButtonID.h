#pragma once
#include "CoreMinimal.h"
#include "EMapScreenMouseButtonID.generated.h"

UENUM(BlueprintType)
enum EMapScreenMouseButtonID {
    MOUSE_BUTTON_LEFT,
    MOUSE_BUTTON_RIGHT,
    MOUSE_BUTTON_WHEEL,
    MOUSE_BUTTON_MAX UMETA(Hidden),
};

