#pragma once
#include "CoreMinimal.h"
#include "LootDropChanceAmendInfo.generated.h"

USTRUCT(BlueprintType)
struct FLootDropChanceAmendInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentChance;
    
    PHOENIX_API FLootDropChanceAmendInfo();
};

