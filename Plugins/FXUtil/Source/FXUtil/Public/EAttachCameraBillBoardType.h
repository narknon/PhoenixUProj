#pragma once
#include "CoreMinimal.h"
#include "EAttachCameraBillBoardType.generated.h"

UENUM(BlueprintType)
enum class EAttachCameraBillBoardType : uint8 {
    ACBBT_ZX,
    ACBBT_YX,
    ACBBT_XZ,
    ACBBT_XY,
    ACBBT_X,
    ACBBT_MAX UMETA(Hidden),
};

