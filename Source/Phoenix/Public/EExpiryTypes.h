#pragma once
#include "CoreMinimal.h"
#include "EExpiryTypes.generated.h"

UENUM(BlueprintType)
enum class EExpiryTypes : uint8 {
    ALL,
    LootDrop,
    Infirmary,
    Count,
};

