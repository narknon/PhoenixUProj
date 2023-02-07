#pragma once
#include "CoreMinimal.h"
#include "ELightCullingLightStatus.generated.h"

UENUM(BlueprintType)
enum class ELightCullingLightStatus : uint8 {
    Unmanaged,
    Ignored,
    Managed,
};

