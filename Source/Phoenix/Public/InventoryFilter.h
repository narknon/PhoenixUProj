#pragma once
#include "CoreMinimal.h"
#include "InventoryFilter.generated.h"

USTRUCT(BlueprintType)
struct FInventoryFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ColumnName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TableName;
    
    PHOENIX_API FInventoryFilter();
};

