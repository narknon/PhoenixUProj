#pragma once
#include "CoreMinimal.h"
#include "EInventoryObjectSpawnType.generated.h"

UENUM(BlueprintType)
enum EInventoryObjectSpawnType {
    InventoryObjectInLevel,
    InventoryObjectDropped,
    InventoryObjectSpawner,
};

