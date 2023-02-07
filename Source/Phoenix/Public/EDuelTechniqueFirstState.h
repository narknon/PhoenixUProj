#pragma once
#include "CoreMinimal.h"
#include "EDuelTechniqueFirstState.generated.h"

UENUM(BlueprintType)
enum class EDuelTechniqueFirstState : uint8 {
    None,
    Frozen,
    OnFire,
    InAir,
    Transformed,
};

