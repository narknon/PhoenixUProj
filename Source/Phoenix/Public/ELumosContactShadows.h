#pragma once
#include "CoreMinimal.h"
#include "ELumosContactShadows.generated.h"

UENUM(BlueprintType)
enum class ELumosContactShadows : uint8 {
    None,
    WorldSpace,
    DepthUnits,
};

