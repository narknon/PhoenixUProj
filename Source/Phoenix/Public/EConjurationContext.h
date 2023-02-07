#pragma once
#include "CoreMinimal.h"
#include "EConjurationContext.generated.h"

UENUM(BlueprintType)
enum class EConjurationContext : uint8 {
    None,
    Sanctuary,
    Biome_Coastal,
    Biome_Forest,
    Biome_Grassland,
    Biome_Swamp,
    Biome_Tundra,
    DevCustomRoom,
};

