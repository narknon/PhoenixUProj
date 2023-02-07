#pragma once
#include "CoreMinimal.h"
#include "EChromaSDKMouseLed.generated.h"

UENUM(BlueprintType)
namespace EChromaSDKMouseLed {
    enum Type {
        ML_SCROLLWHEEL,
        ML_LOGO,
        ML_BACKLIGHT,
        ML_LEFT_SIDE1,
        ML_LEFT_SIDE2,
        ML_LEFT_SIDE3,
        ML_LEFT_SIDE4,
        ML_LEFT_SIDE5,
        ML_LEFT_SIDE6,
        ML_LEFT_SIDE7,
        ML_BOTTOM1,
        ML_BOTTOM2,
        ML_BOTTOM3,
        ML_BOTTOM4,
        ML_BOTTOM5,
        ML_RIGHT_SIDE1,
        ML_RIGHT_SIDE2,
        ML_RIGHT_SIDE3,
        ML_RIGHT_SIDE4,
        ML_RIGHT_SIDE5,
        ML_RIGHT_SIDE6,
        ML_RIGHT_SIDE7,
        ML_MAX UMETA(Hidden),
    };
}

