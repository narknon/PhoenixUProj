#pragma once
#include "CoreMinimal.h"
#include "ETransfigurationPlacementError.generated.h"

UENUM(BlueprintType)
enum class ETransfigurationPlacementError : uint8 {
    NoError,
    NotOnSurface,
    NotInPlayableSpace,
    SpaceOccupied,
};

