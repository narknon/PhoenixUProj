#pragma once
#include "CoreMinimal.h"
#include "EFacialAnimType.generated.h"

UENUM(BlueprintType)
enum EFacialAnimType {
    FACIAL_ANIM_NONE,
    FACIAL_ANIM_TALK,
    FACIAL_ANIM_EAT,
    FACIAL_ANIM_DRINK,
    FACIAL_ANIM_LAUGH,
    FACIAL_ANIM_CHEER,
    FACIAL_ANIM_SLEEP,
    FACIAL_ANIM_BUMPED,
    FACIAL_ANIM_LISTEN,
    FACIAL_ANIM_THINK,
    FACIAL_ANIM_MAX UMETA(Hidden),
};

