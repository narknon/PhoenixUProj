#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EGenderEnum.h"
#include "EGearSlotIDEnum.h"
#include "GearItem.h"
#include "GearItemID.h"
#include "GearStatRecipeData.h"
#include "GearStatType.h"
#include "GearTraitRecipeData.h"
#include "GearUI.h"
#include "ObjectHandles.h"
#include "GearManager.generated.h"

class AActor;
class UGearAppearanceItemDefinition;
class UGearManager;

UCLASS(Blueprintable)
class PHOENIX_API UGearManager : public UObject {
    GENERATED_BODY()
public:
    UGearManager();
    UFUNCTION(BlueprintCallable)
    static int32 UpgradeGearStatOnLoom(FGearItemID itemToUpgrade, FGearStatRecipeData UpgradeData, bool bIgnoreIngredients);
    
    UFUNCTION(BlueprintCallable)
    static bool UpdateGearOutfitItems(AActor* Actor, const bool UpdateIfNothingEquipped, const bool bIncludeSlotDefaultGear, const FString& GearActorID);
    
    UFUNCTION(BlueprintCallable)
    static bool UnequipSlotID(const FString& ActorId, EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable)
    static bool UnequipActorSlotID(AActor* Actor, EGearSlotIDEnum SlotID, const bool bIncludeSlotDefaultGear);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EGearSlotIDEnum StringToGearSlotID(const FString& SlotID);
    
    UFUNCTION(BlueprintCallable)
    static void SetHoodPosition(AActor* Actor, const FGearItemID& GearItemID, bool bHoodUp, bool bRebuildCharacter);
    
    UFUNCTION(BlueprintCallable)
    static bool SetGearStat(const FName& GearID, const FName& Variation, const FName& StatName, int32 StatValue);
    
    UFUNCTION(BlueprintCallable)
    static bool SetForcedGearAppearances(const TMap<EGearSlotIDEnum, FName>& GearAppearanceNames);
    
    UFUNCTION(BlueprintCallable)
    static bool SetEquippedGearItemID(const FString& ActorId, const FGearItemID& GearItemID);
    
    UFUNCTION(BlueprintCallable)
    static bool SetEquippedGearAppearanceOverrideID(const FString& ActorId, const FString& GearAppearanceID);
    
    UFUNCTION(BlueprintCallable)
    static bool SetActorsEquippedGearAppearanceOverrideID(AActor* Actor, const FString& GearAppearanceOverrideID);
    
    UFUNCTION(BlueprintCallable)
    static bool SetActorEquippedGearItemID(AActor* Actor, const FGearItemID& GearItemID, const bool bIncludeSlotDefaultGear);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveGearAppearanceOverride(const FString& ActorId, FGearItemID GearItemID);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveForcedGearAppearances(const TArray<EGearSlotIDEnum>& GearSlotIDs);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveAllForcedGearAppearances();
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveActorGearAppearanceOverride(AActor* Actor, FGearItemID GearItemID);
    
    UFUNCTION(BlueprintCallable)
    static bool PreviewGear(AActor* Actor, FName GearID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FObjectHandles PreloadGearIds(EGenderEnum Gender, const TArray<FName>& GearIDs);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
public:
    UFUNCTION(BlueprintCallable)
    static bool IsHoodUp(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static bool IsHooded(AActor* Actor, EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable)
    static bool IsGearItemHoodUp(const FGearItemID& GearItemID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsGearItemEquippable(FGearItemID GearID);
    
    UFUNCTION(BlueprintCallable)
    static bool IsGear(FName ItemId);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FGearItemID> IdentifyAllItems();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FGearItemID> GetUnidentifiedGear();
    
    UFUNCTION(BlueprintCallable)
    static EGearSlotIDEnum GetSlotIDFromGearID(const FName& GearID);
    
    UFUNCTION(BlueprintCallable)
    static FName GetRarityFromGearItemID(FName GearID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FString> GetOutFitItemTypesBySlotID(EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetNumOfStatUpgradeForGearItem(FGearItemID itemToCheck);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetMaxUpgradeForGearItem(const FGearItem& GearItem);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EGearSlotIDEnum GetLastPreviewedGearSlot();
    
    UFUNCTION(BlueprintCallable)
    static void GetGearTraitRecipes(TArray<FGearTraitRecipeData>& AllRecipes, FName RarityTier);
    
    UFUNCTION(BlueprintCallable)
    static FGearStatRecipeData GetGearStatsUpgradeRecipe(const FGearItem& GearItem, TEnumAsByte<GearStatType> StatType, int32 NewLevel);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetGearMaxTraitSlots(const FName& GearID);
    
    UFUNCTION(BlueprintCallable)
    static bool GetGearItemDynamic(const FGearItemID& GearItemID, FGearItem& GearItem);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetGearItem(const FGearItemID& GearItemID, FGearItem& OutGearItem);
    
    UFUNCTION(BlueprintCallable)
    static FName GetGearIconID(EGenderEnum Gender, const FName& GearID);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetGearEmptyTraitSlots(const FName& GearID, const FName& Variation);
    
    UFUNCTION(BlueprintCallable)
    static TArray<TSoftObjectPtr<UGearAppearanceItemDefinition>> GetGearAppearanceItemDefinitions(EGenderEnum Gender, const TArray<FName>& GearAppearanceIDs);
    
private:
    UFUNCTION(BlueprintCallable)
    static TMap<FName, FName> GetGearAppearanceFromGearIDs(const TArray<FName>& GearIDs);
    
public:
    UFUNCTION(BlueprintCallable)
    static void GetGearAbilityUIInfo(const FGearItem& Item, TArray<FGearUI>& OutGearUI);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGearItemID GetEquippedGearItemID(const FString& ActorId, EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetEquippedGearAppearanceOverrideID(const FString& ActorId, EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable)
    static TMap<FName, FName> GetDefaultPlayerGearAndAppearance();
    
    UFUNCTION(BlueprintCallable)
    static bool GetCanApplyGearTraitToGear(const FGearTraitRecipeData& Trait, const FName& GearID, const FName& GearVariation, FString& OutErrorStringKey);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FGearItemID> GetAvailableGearItemIDs(const FString& ActorId, EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FString> GetAvailableGearAppearanceOverrideIDs(const FString& ActorId, EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FGearItemID> GetAvailableAndEquippedGearItemIDs(const FString& ActorId, EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FString> GetAllGearSlotIDs();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetAllGearIDs(const EGearSlotIDEnum SlotID, TArray<FName>& GearIDs);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FGearItemID> GetAllEquippedGearItemIDs(const FString& ActorId);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FGearItemID> GetAllAvailableGearItemIDsSorted(const FString& ActorId, EGearSlotIDEnum SortedSlotID);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FGearItemID> GetAllActorEquippedGearItemID(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static FName GetActorGearIconID(AActor* Actor, const FName& GearID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGearItemID GetActorEquippedGearItemID(AActor* Actor, EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable)
    static UGearManager* Get();
    
    UFUNCTION(BlueprintCallable)
    static void GenerateGearAndEquip(FName GearID);
    
    UFUNCTION(BlueprintCallable)
    static FGearItemID GenerateGearAndAddToInventory(FName GearID, bool IsIdentified);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GearSlotIDToString(EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable)
    static bool EditorLoadGearAppearance(AActor* Actor, const FString& GearAppearanceID, const FString& HouseIDOverride);
    
    UFUNCTION(BlueprintCallable)
    static bool EditorLoadGear(AActor* Actor, const FString& GearID, bool bResetToEquipped);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool EditorDoesGearAppearanceHaveHouseOverrides(AActor* Actor, const FString& GearAppearanceID);
    
    UFUNCTION(BlueprintCallable)
    static bool EditorClearSlot(AActor* Actor, EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool DoesGearHaveAppearanceOverride(FGearItemID Gear);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<GearStatType> DefineSecondaryGearStatTypeFromSlot(EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<GearStatType> DefineGearStatTypeFromSlot(EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool CanUnequipSlotID(const FString& ActorId, EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool CanUnequipActorSlotID(AActor* Actor, EGearSlotIDEnum SlotID);
    
    UFUNCTION(BlueprintCallable)
    static int32 CalculateUpgradeAmountForGearItem(FGearItemID itemToUpgrade, int32 Upgrade);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddGearUpgradeItems(FName Rarity, TEnumAsByte<GearStatType> StatType, int32 Level);
    
    UFUNCTION(BlueprintCallable)
    static bool AddGearTrait(const FName& GearID, const FName& Variation, const FName& TraitID);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddGearAbilityItems(FName GearAbility);
    
    UFUNCTION(BlueprintCallable)
    static bool AddCraftGearTrait(const FGearTraitRecipeData& Trait, const FGearItemID GearItemID, FString& ErrorString);
    
};

