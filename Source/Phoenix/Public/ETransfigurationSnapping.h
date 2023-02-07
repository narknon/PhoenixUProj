#pragma once
#include "CoreMinimal.h"
#include "ETransfigurationSnapping.generated.h"

UENUM(BlueprintType)
enum class ETransfigurationSnapping : uint8 {
    NoSnapping,
    ConjurationSurface,
    Fixed,
    PowerpointSnapping,
    WallSnapping,
};

