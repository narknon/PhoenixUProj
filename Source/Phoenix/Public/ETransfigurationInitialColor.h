#pragma once
#include "CoreMinimal.h"
#include "ETransfigurationInitialColor.generated.h"

UENUM(BlueprintType)
enum class ETransfigurationInitialColor : uint8 {
    Default,
    AlwaysDefaultColor,
    FromPlayersHouse,
};

