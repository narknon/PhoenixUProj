#pragma once
#include "CoreMinimal.h"
#include "EDifficulty.generated.h"

UENUM(BlueprintType)
enum class EDifficulty : uint8 {
    Story,
    Easy,
    Medium,
    Hard,
};

