#pragma once
#include "CoreMinimal.h"
#include "EManagedFacialEmotionPriority.generated.h"

UENUM(BlueprintType)
enum class EManagedFacialEmotionPriority : uint8 {
    AMBIENT,
    MISSION,
    MECHANIC,
    ABLE,
    ANIM,
    SCENERIG_AMBIENT,
    SCENERIG,
    DIALOG,
};

