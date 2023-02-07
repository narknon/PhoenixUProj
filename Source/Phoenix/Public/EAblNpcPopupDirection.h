#pragma once
#include "CoreMinimal.h"
#include "EAblNpcPopupDirection.generated.h"

UENUM(BlueprintType)
enum class EAblNpcPopupDirection : uint8 {
    Forward,
    Backward,
    Left,
    Right,
};

