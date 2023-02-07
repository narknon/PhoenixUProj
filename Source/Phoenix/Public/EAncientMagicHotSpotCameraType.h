#pragma once
#include "CoreMinimal.h"
#include "EAncientMagicHotSpotCameraType.generated.h"

UENUM(BlueprintType)
enum class EAncientMagicHotSpotCameraType : uint8 {
    None,
    OrbitClose,
    OrbitFar,
    PullBack,
};

