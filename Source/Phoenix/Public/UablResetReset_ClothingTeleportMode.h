#pragma once
#include "CoreMinimal.h"
#include "UablResetReset_ClothingTeleportMode.generated.h"

UENUM(BlueprintType)
enum class UablResetReset_ClothingTeleportMode : uint8 {
    Teleport,
    TeleportAndReset,
    UablResetReset_MAX UMETA(Hidden),
};

