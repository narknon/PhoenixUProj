#pragma once
#include "CoreMinimal.h"
#include "FCharacterBoneProjectionMotionType.generated.h"

UENUM(BlueprintType)
enum class FCharacterBoneProjectionMotionType : uint8 {
    Stationary,
    SphericalProjection,
    CapsuleProjection,
    Crawling,
};

