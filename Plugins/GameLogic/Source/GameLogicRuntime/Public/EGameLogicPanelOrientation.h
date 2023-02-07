#pragma once
#include "CoreMinimal.h"
#include "EGameLogicPanelOrientation.generated.h"

UENUM(BlueprintType)
enum class EGameLogicPanelOrientation : uint8 {
    LeftSide,
    Top,
    TopRight,
    Bottom,
};

