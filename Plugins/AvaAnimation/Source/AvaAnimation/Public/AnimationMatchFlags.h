#pragma once
#include "CoreMinimal.h"
#include "AnimationMatchFlags.generated.h"

UENUM(BlueprintType)
enum AnimationMatchFlags {
    MATCH_FIRST_FRAME,
    MATCH_LAST_FRAME,
    MATCH_MAX UMETA(Hidden),
};

