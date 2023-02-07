#pragma once
#include "CoreMinimal.h"
#include "AnimationTypeToFetch.generated.h"

UENUM(BlueprintType)
enum AnimationTypeToFetch {
    ANIMFETCH_UNKNOWN,
    ANIMFETCH_ENTER,
    ANIMFETCH_EXIT,
    ANIMFETCH_MAX UMETA(Hidden),
};

