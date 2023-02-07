#pragma once
#include "CoreMinimal.h"
#include "ERagdollPoseDrivingMode.generated.h"

UENUM(BlueprintType)
enum class ERagdollPoseDrivingMode : uint8 {
    Strong,
    Weak,
    Inactive,
    Dead,
    Petrified,
};

