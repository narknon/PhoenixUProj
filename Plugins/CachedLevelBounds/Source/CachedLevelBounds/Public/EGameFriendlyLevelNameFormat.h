#pragma once
#include "CoreMinimal.h"
#include "EGameFriendlyLevelNameFormat.generated.h"

UENUM(BlueprintType)
enum class EGameFriendlyLevelNameFormat : uint8 {
    Game,
    Raw,
    GameAndRaw,
    RawAndGame,
};

