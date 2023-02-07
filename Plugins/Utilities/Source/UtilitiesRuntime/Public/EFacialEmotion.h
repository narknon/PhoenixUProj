#pragma once
#include "CoreMinimal.h"
#include "EFacialEmotion.generated.h"

UENUM(BlueprintType)
enum class EFacialEmotion : uint8 {
    NONE,
    ALARM,
    AMUSEMENT,
    ANGRY,
    ANGUISH,
    ANNOYANCE,
    ANTICIPATION,
    ANXIETY,
    CONFUSED,
    DELIGHT,
    DISGUST,
    FEAR,
    HAPPY,
    IMPRESSED,
    NEUTRAL,
    PACIFY,
    SAD,
    SICK,
    SLEEP,
    SURPRISE,
    TRUST,
    VALOR,
    MAX,
};

