#pragma once
#include "CoreMinimal.h"
#include "InventoryResult.h"
#include "CachedInventory.generated.h"

USTRUCT(BlueprintType)
struct FCachedInventory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FInventoryResult> CachedInventory;
    
    PHOENIX_API FCachedInventory();
};

