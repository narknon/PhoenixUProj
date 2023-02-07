#pragma once
#include "CoreMinimal.h"
#include "EPhoenixScalabilityPlatform.generated.h"

UENUM(BlueprintType)
enum class EPhoenixScalabilityPlatform : uint8 {
    Unknown,
    PC,
    PS4,
    PS5,
    Switch,
    XBoxOne,
    XSX,
};

