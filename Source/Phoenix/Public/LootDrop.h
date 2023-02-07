#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LootSlot.h"
#include "LootDrop.generated.h"

UCLASS(Blueprintable)
class ULootDrop : public UObject {
    GENERATED_BODY()
public:
    ULootDrop();
    UFUNCTION(BlueprintCallable)
    void SetContainerID(const FString& ContainerID);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveItems(const FString& Item, int32 Quantity, const FString& Variation);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAllItems();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LootDropGenerateContents(const FString& ContentCategory, int32 Level);
    
    UFUNCTION(BlueprintCallable)
    TArray<FLootSlot> GetContents();
    
    UFUNCTION(BlueprintCallable)
    FString GetContainerID();
    
    UFUNCTION(BlueprintCallable)
    TArray<FLootSlot> GenerateContents(const FString& Category, int32 Level, bool bForceGeneration);
    
    UFUNCTION(BlueprintCallable)
    bool AddItems(const FString& Item, int32 Quantity, const FString& Variation, bool IsUnique, bool IsAlreadyIdentified);
    
};

