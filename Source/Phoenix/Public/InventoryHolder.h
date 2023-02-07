#pragma once
#include "CoreMinimal.h"
#include "InventoryResult.h"
#include "InventoryHolder.generated.h"

USTRUCT(BlueprintType)
struct FInventoryHolder {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HolderID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInventoryResult> InventoryResults;
    
    PHOENIX_API FInventoryHolder();
};

