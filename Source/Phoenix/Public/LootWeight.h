#pragma once
#include "CoreMinimal.h"
#include "LootWeight.generated.h"

USTRUCT(BlueprintType)
struct FLootWeight {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeightMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeightMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemIndex;
    
    PHOENIX_API FLootWeight();
};

