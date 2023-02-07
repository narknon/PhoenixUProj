#pragma once
#include "CoreMinimal.h"
#include "EFollowCameraType.generated.h"

UENUM(BlueprintType)
enum class EFollowCameraType : uint8 {
    FCT_OFF,
    FCT_FULL,
    FCT_XYONLY,
    FCT_FIXEDZ,
    FCT_OFFSETZ,
    FCT_MAX UMETA(Hidden),
};

