#pragma once
#include "CoreMinimal.h"
#include "ESkinFXEffectEndStyle.generated.h"

UENUM(BlueprintType)
enum class ESkinFXEffectEndStyle : uint8 {
    Immediately,
    JumpToRelease,
    EndSustainHold,
};

