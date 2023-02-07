#pragma once
#include "CoreMinimal.h"
#include "EMapPlayerHouseTypes.generated.h"

UENUM(BlueprintType)
enum class EMapPlayerHouseTypes : uint8 {
    MAP_PLAYER_HOUSE_GRYFFINDOR,
    MAP_PLAYER_HOUSE_SLYTHERIN,
    MAP_PLAYER_HOUSE_HUFFLEPUFF,
    MAP_PLAYER_HOUSE_RAVENCLAW,
    MAP_PLAYER_HOUSE_MAX UMETA(Hidden),
};

