#pragma once
#include "CoreMinimal.h"
#include "EDevilsSnareState.generated.h"

UENUM(BlueprintType)
enum class EDevilsSnareState : uint8 {
    Hidden,
    Idle,
    Recoiling,
    Regrowing,
    Grabbing,
};

