#pragma once
#include "CoreMinimal.h"
#include "LootSlot.h"
#include "LootContainer.generated.h"

USTRUCT(BlueprintType)
struct FLootContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString UniqueContainerID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLootSlot> Slots;
    
    PHOENIX_API FLootContainer();
};

