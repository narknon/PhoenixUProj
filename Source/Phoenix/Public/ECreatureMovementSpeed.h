#pragma once
#include "CoreMinimal.h"
#include "ECreatureMovementSpeed.generated.h"

UENUM(BlueprintType)
enum class ECreatureMovementSpeed : uint8 {
    Stop,
    Walk,
    Jog,
    Sprint,
    Num,
};

