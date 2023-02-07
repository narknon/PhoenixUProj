#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CachedInventory.h"
#include "InventoryManager.generated.h"

UCLASS(Blueprintable)
class UInventoryManager : public UObject {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FItemConsumed, const FName&, InCharacterID, const FName&, InItemID);
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FCachedInventory> m_cachedInventories;
    
public:
    UInventoryManager();
    UFUNCTION(BlueprintCallable, Exec)
    void Test_SetOffenseStat(const FString& GearID, const FString& Variation, int32 Offense);
    
    UFUNCTION(BlueprintCallable, Exec)
    void Test_SetDefenseStat(const FString& GearID, const FString& Variation, int32 Defense);
    
    UFUNCTION(BlueprintCallable, Exec)
    void Test_SetCooldownStat(const FString& GearID, const FString& Variation, int32 Cooldown);
    
    UFUNCTION(BlueprintCallable, Exec)
    void Test_GetGearEmptyTraitSlots(const FString& GearID, const FString& Variation);
    
    UFUNCTION(BlueprintCallable, Exec)
    void Test_AddGearTrait(const FString& GearID, const FString& Variation, const FString& TraitID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ResetInventory(const FName CharacterID, FName HolderID, bool ResetKeepOnResetItems);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void LootContainerStats(const FString& ContainerID, int32 iterations);
    
    UFUNCTION(BlueprintCallable, Exec)
    void InventoryUseItem(const FString& ItemId);
    
    UFUNCTION(BlueprintCallable, Exec)
    void InventoryAddTool(const FString& ToolID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void InventoryAddHerbologyGear();
    
    UFUNCTION(BlueprintCallable, Exec)
    void InventoryAddGenericGear();
    
    UFUNCTION(BlueprintCallable, Exec)
    void InventoryAddGear(const FString& ItemId, const FString& Variation);
    
    UFUNCTION(BlueprintCallable, Exec)
    void InventoryAddDadaGear();
    
    UFUNCTION(BlueprintCallable, Exec)
    void InventoryAdd(const FString& ItemId, int32 Quantity);
    
};

