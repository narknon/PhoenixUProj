#pragma once
#include "CoreMinimal.h"
#include "USceneAction_ResetClothSim_ClothingTeleportMode.generated.h"

UENUM(BlueprintType)
enum class USceneAction_ResetClothSim_ClothingTeleportMode : uint8 {
    Teleport,
    TeleportAndReset,
    USceneAction_ResetClothSim_MAX UMETA(Hidden),
};

