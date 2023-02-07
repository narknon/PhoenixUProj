#pragma once
#include "CoreMinimal.h"
#include "ESkinFXMaterialOverrideType.generated.h"

UENUM(BlueprintType)
enum class ESkinFXMaterialOverrideType : uint8 {
    UseMeshMaterials,
    UseSingleOverride,
    MatchedIndexOverride,
};

