#pragma once
#include "CoreMinimal.h"
#include "EWingardiumState.generated.h"

UENUM(BlueprintType)
enum class EWingardiumState : uint8 {
    Inactive,
    Rise,
    MoveObject,
    End,
};

