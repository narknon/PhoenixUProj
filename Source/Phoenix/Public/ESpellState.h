#pragma once
#include "CoreMinimal.h"
#include "ESpellState.generated.h"

UENUM(BlueprintType)
enum class ESpellState : uint8 {
    Cast,
    Success,
    Charged,
    Channeling,
    Other,
};

