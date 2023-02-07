#pragma once
#include "CoreMinimal.h"
#include "EInventoryTabCategory.generated.h"

UENUM(BlueprintType)
enum class EInventoryTabCategory : uint8 {
    DefaultInventory,
    QuestItems,
};

