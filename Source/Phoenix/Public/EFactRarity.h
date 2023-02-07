#pragma once
#include "CoreMinimal.h"
#include "EFactRarity.generated.h"

UENUM(BlueprintType)
enum class EFactRarity : uint8 {
    F_Common,
    F_Uncommon,
    F_Rare,
    F_Mythic,
    F_MAX UMETA(Hidden),
};

