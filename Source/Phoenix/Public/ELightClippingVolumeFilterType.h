#pragma once
#include "CoreMinimal.h"
#include "ELightClippingVolumeFilterType.generated.h"

UENUM(BlueprintType)
enum class ELightClippingVolumeFilterType : uint8 {
    None,
    OnlyInside,
    OnlyOutside,
};

