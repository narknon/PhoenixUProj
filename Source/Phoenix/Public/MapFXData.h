#pragma once
#include "CoreMinimal.h"
#include "MapFXEntry.h"
#include "MapFXData.generated.h"

USTRUCT(BlueprintType)
struct FMapFXData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMapFXEntry> Effects;
    
    PHOENIX_API FMapFXData();
};

