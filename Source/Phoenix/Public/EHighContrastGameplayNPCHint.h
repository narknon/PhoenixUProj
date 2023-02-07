#pragma once
#include "CoreMinimal.h"
#include "EHighContrastGameplayNPCHint.generated.h"

UENUM(BlueprintType)
enum class EHighContrastGameplayNPCHint : uint8 {
    Enemy,
    Companion,
    Friendly,
};

