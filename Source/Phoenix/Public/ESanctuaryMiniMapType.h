#pragma once
#include "CoreMinimal.h"
#include "ESanctuaryMiniMapType.generated.h"

UENUM(BlueprintType)
namespace ESanctuaryMiniMapType {
    enum Type {
        MINIMAP_TYPE_NONE,
        MINIMAP_TYPE_HUB,
        MINIMAP_TYPE_GRASSLAND,
        MINIMAP_TYPE_FOREST,
        MINIMAP_TYPE_COAST,
        MINIMAP_TYPE_SWAMP,
        MINIMAP_TYPE_STUDY,
        MINIMAP_TYPE_MAX UMETA(Hidden),
    };
}

