#pragma once
#include "CoreMinimal.h"
#include "ESceneAction_ClothingTeleportMode.generated.h"

UENUM(BlueprintType)
enum class ESceneAction_ClothingTeleportMode : uint8 {
    None,
    Teleport,
    TeleportAndReset,
    ESceneAction_MAX UMETA(Hidden),
};

