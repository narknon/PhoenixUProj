#pragma once
#include "CoreMinimal.h"
#include "InventoryResult.h"
#include "InventoryLoadout.generated.h"

USTRUCT(BlueprintType)
struct FInventoryLoadout {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInventoryResult> InventoryItemArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ActiveItemIndex;
    
    PHOENIX_API FInventoryLoadout();
};

