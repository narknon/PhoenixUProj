#pragma once
#include "CoreMinimal.h"
#include "EOverlapEffectsEvent.generated.h"

UENUM(BlueprintType)
enum class EOverlapEffectsEvent : uint8 {
    BeginOverlap,
    EndOverlap,
    Hit,
    Tick,
};

