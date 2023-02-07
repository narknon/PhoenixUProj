#pragma once
#include "CoreMinimal.h"
#include "EPostDeathCleanupEffect.generated.h"

UENUM(BlueprintType)
enum class EPostDeathCleanupEffect : uint8 {
    Dissolve,
    Fade,
    Destroy,
    None,
};

