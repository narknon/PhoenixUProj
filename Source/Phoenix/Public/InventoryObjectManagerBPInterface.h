#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemProperties.h"
#include "InventoryObjectManagerBPInterface.generated.h"

class UStaticMesh;

UCLASS(Blueprintable)
class UInventoryObjectManagerBPInterface : public UObject {
    GENERATED_BODY()
public:
    UInventoryObjectManagerBPInterface();
    UFUNCTION(BlueprintCallable)
    static UStaticMesh* GetItemStaticMesh(const FName InventoryObjectID);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetItemSellPrice(int32 DbPrice, int32 EconomyValue);
    
    UFUNCTION(BlueprintCallable)
    static bool GetItemProperties(const FName InventoryObjectID, FItemProperties& ItemProperties, FName Variation);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetInventorySlotCapacityByName(FName ItemId, FName ItemType, FName SlotLevelName);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetInventorySlotCapacityByIndex(FName ItemId, FName ItemType, int32 SlotLevelIndex);
    
};

