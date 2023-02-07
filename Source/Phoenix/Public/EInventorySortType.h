#pragma once
#include "CoreMinimal.h"
#include "EInventorySortType.generated.h"

UENUM(BlueprintType)
enum class EInventorySortType : uint8 {
    Inventory_Sort_Type,
    Inventory_Sort_Newest,
    Inventory_Sort_Value,
    Inventory_Sort_Alphabetical,
    Inventory_Sort_Count,
    Inventory_Sort_MAX UMETA(Hidden),
};

