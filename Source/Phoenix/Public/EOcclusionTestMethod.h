#pragma once
#include "CoreMinimal.h"
#include "EOcclusionTestMethod.generated.h"

UENUM(BlueprintType)
enum class EOcclusionTestMethod : uint8 {
    PrimaryOcclusionOnly,
    HulaHoop_4,
    FacingPortal_8,
    EdgeOnPortal_12,
};

