#pragma once
#include "CoreMinimal.h"
#include "OdcObstacleBehavior.generated.h"

UENUM()
enum class OdcObstacleBehavior : int32 {
    Automatic,
    NoEffectPenalty,
    NoEffectImpassable,
    PenaltyImpassable,
};

