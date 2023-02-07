#pragma once
#include "CoreMinimal.h"
#include "EBentDirectionalLightWindowLocation.generated.h"

UENUM(BlueprintType)
enum class EBentDirectionalLightWindowLocation : uint8 {
    TopLeft,
    TopRight,
    BottomRight,
    BottomLeft,
    Top,
    Right,
    Bottom,
    Left,
    Center,
};

