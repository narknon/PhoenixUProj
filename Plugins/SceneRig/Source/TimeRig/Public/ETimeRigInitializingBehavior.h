#pragma once
#include "CoreMinimal.h"
#include "ETimeRigInitializingBehavior.generated.h"

UENUM(BlueprintType)
enum class ETimeRigInitializingBehavior : uint8 {
    UseSRSettings,
    None,
    ShowLoadingIcon,
    FadeToBlackAndShowLoadingIcon,
    HardToBlackAndShowLoadingIcon,
    FadeToBlackHoldFade,
    BehindCurtain,
};

