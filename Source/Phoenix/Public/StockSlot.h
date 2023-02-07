#pragma once
#include "CoreMinimal.h"
#include "StockSlot.generated.h"

USTRUCT(BlueprintType)
struct FStockSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Quantity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Quality;
    
    PHOENIX_API FStockSlot();
};

