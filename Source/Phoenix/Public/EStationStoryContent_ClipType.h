#pragma once
#include "CoreMinimal.h"
#include "EStationStoryContent_ClipType.generated.h"

UENUM(BlueprintType)
enum class EStationStoryContent_ClipType : uint8 {
    Enter,
    TransitionIn,
    Idle,
    TransitionOut,
    Exit,
    EStationStoryContent_MAX UMETA(Hidden),
};

