#include "GearManager.h"

class AActor;
class UGearAppearanceItemDefinition;
class UGearManager;

int32 UGearManager::UpgradeGearStatOnLoom(FGearItemID itemToUpgrade, FGearStatRecipeData UpgradeData, bool bIgnoreIngredients) {
    return 0;
}

bool UGearManager::UpdateGearOutfitItems(AActor* Actor, const bool UpdateIfNothingEquipped, const bool bIncludeSlotDefaultGear, const FString& GearActorID) {
    return false;
}

bool UGearManager::UnequipSlotID(const FString& ActorId, EGearSlotIDEnum SlotID) {
    return false;
}

bool UGearManager::UnequipActorSlotID(AActor* Actor, EGearSlotIDEnum SlotID, const bool bIncludeSlotDefaultGear) {
    return false;
}

EGearSlotIDEnum UGearManager::StringToGearSlotID(const FString& SlotID) {
    return EGearSlotIDEnum::HEAD;
}

void UGearManager::SetHoodPosition(AActor* Actor, const FGearItemID& GearItemID, bool bHoodUp, bool bRebuildCharacter) {
}

bool UGearManager::SetGearStat(const FName& GearID, const FName& Variation, const FName& StatName, int32 StatValue) {
    return false;
}

bool UGearManager::SetForcedGearAppearances(const TMap<EGearSlotIDEnum, FName>& GearAppearanceNames) {
    return false;
}

bool UGearManager::SetEquippedGearItemID(const FString& ActorId, const FGearItemID& GearItemID) {
    return false;
}

bool UGearManager::SetEquippedGearAppearanceOverrideID(const FString& ActorId, const FString& GearAppearanceID) {
    return false;
}

bool UGearManager::SetActorsEquippedGearAppearanceOverrideID(AActor* Actor, const FString& GearAppearanceOverrideID) {
    return false;
}

bool UGearManager::SetActorEquippedGearItemID(AActor* Actor, const FGearItemID& GearItemID, const bool bIncludeSlotDefaultGear) {
    return false;
}

bool UGearManager::RemoveGearAppearanceOverride(const FString& ActorId, FGearItemID GearItemID) {
    return false;
}

bool UGearManager::RemoveForcedGearAppearances(const TArray<EGearSlotIDEnum>& GearSlotIDs) {
    return false;
}

void UGearManager::RemoveAllForcedGearAppearances() {
}

bool UGearManager::RemoveActorGearAppearanceOverride(AActor* Actor, FGearItemID GearItemID) {
    return false;
}

bool UGearManager::PreviewGear(AActor* Actor, FName GearID) {
    return false;
}

FObjectHandles UGearManager::PreloadGearIds(EGenderEnum Gender, const TArray<FName>& GearIDs) {
    return FObjectHandles{};
}

void UGearManager::OnSaveGameLoaded() {
}

bool UGearManager::IsHoodUp(AActor* Actor) {
    return false;
}

bool UGearManager::IsHooded(AActor* Actor, EGearSlotIDEnum SlotID) {
    return false;
}

bool UGearManager::IsGearItemHoodUp(const FGearItemID& GearItemID) {
    return false;
}

bool UGearManager::IsGearItemEquippable(FGearItemID GearID) {
    return false;
}

bool UGearManager::IsGear(FName ItemId) {
    return false;
}

TArray<FGearItemID> UGearManager::IdentifyAllItems() {
    return TArray<FGearItemID>();
}

TArray<FGearItemID> UGearManager::GetUnidentifiedGear() {
    return TArray<FGearItemID>();
}

EGearSlotIDEnum UGearManager::GetSlotIDFromGearID(const FName& GearID) {
    return EGearSlotIDEnum::HEAD;
}

FName UGearManager::GetRarityFromGearItemID(FName GearID) {
    return NAME_None;
}

TArray<FString> UGearManager::GetOutFitItemTypesBySlotID(EGearSlotIDEnum SlotID) {
    return TArray<FString>();
}

int32 UGearManager::GetNumOfStatUpgradeForGearItem(FGearItemID itemToCheck) {
    return 0;
}

int32 UGearManager::GetMaxUpgradeForGearItem(const FGearItem& GearItem) {
    return 0;
}

EGearSlotIDEnum UGearManager::GetLastPreviewedGearSlot() {
    return EGearSlotIDEnum::HEAD;
}

void UGearManager::GetGearTraitRecipes(TArray<FGearTraitRecipeData>& AllRecipes, FName RarityTier) {
}

FGearStatRecipeData UGearManager::GetGearStatsUpgradeRecipe(const FGearItem& GearItem, TEnumAsByte<GearStatType> StatType, int32 NewLevel) {
    return FGearStatRecipeData{};
}

int32 UGearManager::GetGearMaxTraitSlots(const FName& GearID) {
    return 0;
}

bool UGearManager::GetGearItemDynamic(const FGearItemID& GearItemID, FGearItem& GearItem) {
    return false;
}

bool UGearManager::GetGearItem(const FGearItemID& GearItemID, FGearItem& OutGearItem) {
    return false;
}

FName UGearManager::GetGearIconID(EGenderEnum Gender, const FName& GearID) {
    return NAME_None;
}

int32 UGearManager::GetGearEmptyTraitSlots(const FName& GearID, const FName& Variation) {
    return 0;
}

TArray<TSoftObjectPtr<UGearAppearanceItemDefinition>> UGearManager::GetGearAppearanceItemDefinitions(EGenderEnum Gender, const TArray<FName>& GearAppearanceIDs) {
    return TArray<TSoftObjectPtr<UGearAppearanceItemDefinition>>();
}

TMap<FName, FName> UGearManager::GetGearAppearanceFromGearIDs(const TArray<FName>& GearIDs) {
    return TMap<FName, FName>();
}

void UGearManager::GetGearAbilityUIInfo(const FGearItem& Item, TArray<FGearUI>& OutGearUI) {
}

FGearItemID UGearManager::GetEquippedGearItemID(const FString& ActorId, EGearSlotIDEnum SlotID) {
    return FGearItemID{};
}

FString UGearManager::GetEquippedGearAppearanceOverrideID(const FString& ActorId, EGearSlotIDEnum SlotID) {
    return TEXT("");
}

TMap<FName, FName> UGearManager::GetDefaultPlayerGearAndAppearance() {
    return TMap<FName, FName>();
}

bool UGearManager::GetCanApplyGearTraitToGear(const FGearTraitRecipeData& Trait, const FName& GearID, const FName& GearVariation, FString& OutErrorStringKey) {
    return false;
}

TArray<FGearItemID> UGearManager::GetAvailableGearItemIDs(const FString& ActorId, EGearSlotIDEnum SlotID) {
    return TArray<FGearItemID>();
}

TArray<FString> UGearManager::GetAvailableGearAppearanceOverrideIDs(const FString& ActorId, EGearSlotIDEnum SlotID) {
    return TArray<FString>();
}

TArray<FGearItemID> UGearManager::GetAvailableAndEquippedGearItemIDs(const FString& ActorId, EGearSlotIDEnum SlotID) {
    return TArray<FGearItemID>();
}

TArray<FString> UGearManager::GetAllGearSlotIDs() {
    return TArray<FString>();
}

void UGearManager::GetAllGearIDs(const EGearSlotIDEnum SlotID, TArray<FName>& GearIDs) {
}

TArray<FGearItemID> UGearManager::GetAllEquippedGearItemIDs(const FString& ActorId) {
    return TArray<FGearItemID>();
}

TArray<FGearItemID> UGearManager::GetAllAvailableGearItemIDsSorted(const FString& ActorId, EGearSlotIDEnum SortedSlotID) {
    return TArray<FGearItemID>();
}

TArray<FGearItemID> UGearManager::GetAllActorEquippedGearItemID(AActor* Actor) {
    return TArray<FGearItemID>();
}

FName UGearManager::GetActorGearIconID(AActor* Actor, const FName& GearID) {
    return NAME_None;
}

FGearItemID UGearManager::GetActorEquippedGearItemID(AActor* Actor, EGearSlotIDEnum SlotID) {
    return FGearItemID{};
}

UGearManager* UGearManager::Get() {
    return NULL;
}

void UGearManager::GenerateGearAndEquip(FName GearID) {
}

FGearItemID UGearManager::GenerateGearAndAddToInventory(FName GearID, bool IsIdentified) {
    return FGearItemID{};
}

FString UGearManager::GearSlotIDToString(EGearSlotIDEnum SlotID) {
    return TEXT("");
}

bool UGearManager::EditorLoadGearAppearance(AActor* Actor, const FString& GearAppearanceID, const FString& HouseIDOverride) {
    return false;
}

bool UGearManager::EditorLoadGear(AActor* Actor, const FString& GearID, bool bResetToEquipped) {
    return false;
}

bool UGearManager::EditorDoesGearAppearanceHaveHouseOverrides(AActor* Actor, const FString& GearAppearanceID) {
    return false;
}

bool UGearManager::EditorClearSlot(AActor* Actor, EGearSlotIDEnum SlotID) {
    return false;
}

bool UGearManager::DoesGearHaveAppearanceOverride(FGearItemID Gear) {
    return false;
}

TEnumAsByte<GearStatType> UGearManager::DefineSecondaryGearStatTypeFromSlot(EGearSlotIDEnum SlotID) {
    return None;
}

TEnumAsByte<GearStatType> UGearManager::DefineGearStatTypeFromSlot(EGearSlotIDEnum SlotID) {
    return None;
}

bool UGearManager::CanUnequipSlotID(const FString& ActorId, EGearSlotIDEnum SlotID) {
    return false;
}

bool UGearManager::CanUnequipActorSlotID(AActor* Actor, EGearSlotIDEnum SlotID) {
    return false;
}

int32 UGearManager::CalculateUpgradeAmountForGearItem(FGearItemID itemToUpgrade, int32 Upgrade) {
    return 0;
}

void UGearManager::AddGearUpgradeItems(FName Rarity, TEnumAsByte<GearStatType> StatType, int32 Level) {
}

bool UGearManager::AddGearTrait(const FName& GearID, const FName& Variation, const FName& TraitID) {
    return false;
}

void UGearManager::AddGearAbilityItems(FName GearAbility) {
}

bool UGearManager::AddCraftGearTrait(const FGearTraitRecipeData& Trait, const FGearItemID GearItemID, FString& ErrorString) {
    return false;
}

UGearManager::UGearManager() {
}

