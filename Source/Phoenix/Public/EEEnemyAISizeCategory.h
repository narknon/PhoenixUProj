#pragma once
#include "CoreMinimal.h"
#include "EEEnemyAISizeCategory.generated.h"

UENUM(BlueprintType)
enum class EEEnemyAISizeCategory : uint8 {
    None,
    Tiny,
    Small,
    Medium,
    Large,
    Huge,
    Gigantic,
};

