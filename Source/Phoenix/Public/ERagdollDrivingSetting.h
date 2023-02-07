#pragma once
#include "CoreMinimal.h"
#include "ERagdollDrivingSetting.generated.h"

UENUM(BlueprintType)
enum class ERagdollDrivingSetting : uint8 {
    KeepCurrent,
    AlwaysOverride,
    SetIfStronger,
    SetIfWeaker,
    SetIfAlreadyInFullRagdoll,
    SetIfNotAlreadyInFullRagdoll,
};

