#pragma once
#include "CoreMinimal.h"
#include "ESkinFXEffectSwapType.generated.h"

UENUM(BlueprintType)
enum class ESkinFXEffectSwapType : uint8 {
    UsePermutedMaterials,
    InPlaceMIDs,
    MaterialOverride,
};

