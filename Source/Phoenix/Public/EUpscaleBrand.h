#pragma once
#include "CoreMinimal.h"
#include "EUpscaleBrand.generated.h"

UENUM(BlueprintType)
enum class EUpscaleBrand : uint8 {
    None,
    DLSS,
    FSR,
    NIS,
    FSR2,
    XeSS,
};

