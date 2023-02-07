#pragma once
#include "CoreMinimal.h"
#include "EAutoSaveReason.generated.h"

UENUM(BlueprintType)
enum class EAutoSaveReason : uint8 {
    AUTO_SAVE_UNKNOWN,
    AUTO_SAVE_MISSION,
    AUTO_SAVE_TIMER,
    AUTO_SAVE_ALWAYS,
    AUTO_SAVE_GAME_MODE_START_PLAY,
    AUTO_SAVE_INTRO,
    AUTO_SAVE_TEST,
    AUTO_SAVE_MAX UMETA(Hidden),
};

