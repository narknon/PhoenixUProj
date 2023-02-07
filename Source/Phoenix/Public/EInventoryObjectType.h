#pragma once
#include "CoreMinimal.h"
#include "EInventoryObjectType.generated.h"

UENUM(BlueprintType)
enum class EInventoryObjectType : uint8 {
    INVENTORY_OBJECT_TYPE_STANDARD,
    INVENTORY_OBJECT_TYPE_BEAST,
    INVENTORY_OBJECT_TYPE_NAMED_BEAST,
    INVENTORY_OBJECT_TYPE_MAX UMETA(Hidden),
};

