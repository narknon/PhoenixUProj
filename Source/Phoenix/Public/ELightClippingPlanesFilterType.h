#pragma once
#include "CoreMinimal.h"
#include "ELightClippingPlanesFilterType.generated.h"

UENUM(BlueprintType)
enum class ELightClippingPlanesFilterType : uint8 {
    None,
    OnlyNonInverted,
    OnlyInverted,
};

