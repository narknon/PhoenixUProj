#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EInventoryChangeReason.h"
#include "EInventoryObjectType.h"
#include "EStolenType.h"
#include "InventoryFilter.h"
#include "InventoryResult.h"
#include "InventoryManagerInterface.generated.h"

class AActor;

UCLASS(Blueprintable)
class UInventoryManagerInterface : public UObject {
    GENERATED_BODY()
public:
    UInventoryManagerInterface();
    UFUNCTION(BlueprintCallable)
    static bool UseItemByName(const FName CharacterID, FName ItemId, const FName Variation);
    
    UFUNCTION(BlueprintCallable)
    static bool UseItem(const FName CharacterID, FInventoryResult InventoryResult);
    
    UFUNCTION(BlueprintCallable)
    static bool TransferItemToPlayerInventoryBP(FInventoryResult TransferItem, int32 AmountToTransfer);
    
    UFUNCTION(BlueprintCallable)
    static bool TransferItemToContainerBP(FInventoryResult ItemToTransfer, FName CharacterID, FName HolderID, int32 AmountToTransfer);
    
    UFUNCTION(BlueprintCallable)
    static void SetPlayerExpandedInventoryBP(int32 newInventoryAmount);
    
    UFUNCTION(BlueprintCallable)
    static bool SellItemFromPlayerInventoryBP(FInventoryResult TransferItem, int32 SoldCount, FName VendorName, int32& OutKnutsEarned);
    
    UFUNCTION(BlueprintCallable)
    static void ResetInventory(const FName CharacterID, FName HolderID);
    
    UFUNCTION(BlueprintCallable)
    static bool IsAbilityActive(AActor* Actor, FName AbilityName);
    
    UFUNCTION(BlueprintCallable)
    static bool HasAnyInventory(const FName CharacterID, const FName HolderID);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetQuestItems();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetPlayerUnlimitedHolders();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetPlayerStolenItemCount();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetPlayerLimitedHolders();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetPlayerExpandedInventoryBP();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetPlayerAvailableCapacity(FName ItemId, bool UseMaxCapacityWhenNoReturnExcess);
    
    UFUNCTION(BlueprintCallable)
    static FName GetItemInventoryFullString(FName ItemId);
    
    UFUNCTION(BlueprintCallable)
    static bool GetIsInspectableBP(const FString& ItemId);
    
    UFUNCTION(BlueprintCallable)
    static void GetInventoryTypesBP(TArray<FName>& InventoryTypeArray);
    
    UFUNCTION(BlueprintCallable)
    static void GetInventoryTextBP(const FName InCharacterID, const FName InItemTypeID, TArray<FInventoryResult>& InventoryResultArray, const FInventoryFilter InventoryFilter, const FName HolderID, bool SkipLockedItems, bool SpecifiedHolderOnly);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetInventorySellPriceBP(FName CharacterID, FName HolderID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetHolderMaxSlotsBP(FName HolderID);
    
    UFUNCTION(BlueprintCallable)
    static FName GetHolderInventoryFullString(FName HolderID);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetCount(const FName CharacterID, const FName InventoryObjectID, const EInventoryObjectType InventoryObjectType, const EStolenType StolenType, const FName HolderID, const FName Variation);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetCost(const FName InventoryObjectID, const FName Variation);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetContainerMaxSlotsBP(FName ContainerID);
    
    UFUNCTION(BlueprintCallable)
    static bool DropItemBP(FInventoryResult ItemToDrop, int32 AmountToDrop);
    
    UFUNCTION(BlueprintCallable)
    static int32 CanAddItem(const FName CharacterID, const FName ItemId, const FName HolderID, const FName Variation, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static int32 AdjustCount(const FName CharacterID, const FName InventoryObjectID, const int32 Delta, const EInventoryChangeReason Reason, const FName HolderID, const FName Variation, const bool SuppressHUDNotification, const bool SpecialHUDNotification, const FName OtherCharacterID, const bool IsUnique, const bool IsStolen, const bool KeepOnReset);
    
};

