#pragma once
#include "CoreMinimal.h"
#include "EPhysicsMunitionHitType.generated.h"

UENUM()
enum class EPhysicsMunitionHitType : int32 {
    Success,
    Blocked,
    Terrain,
};

