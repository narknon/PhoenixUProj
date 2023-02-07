#pragma once
#include "CoreMinimal.h"
#include "EGlobalLightRigModType.generated.h"

UENUM(BlueprintType)
enum class EGlobalLightRigModType : uint8 {
    Absolute,
    Multiply,
    Add,
    Minimum,
    Maximum,
};

