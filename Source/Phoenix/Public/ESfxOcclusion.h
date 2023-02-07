#pragma once
#include "CoreMinimal.h"
#include "ESfxOcclusion.generated.h"

UENUM(BlueprintType)
enum class ESfxOcclusion : uint8 {
    NoOcclusion_0,
    Single_1,
    HulaHoop_8,
    FacingPortal_16,
    EdgeOnPortal_24,
};

